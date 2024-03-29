/* Open and close files for bison,
   Copyright (C) 1984, 1986, 1989, 1992 Free Software Foundation, Inc.

This file is part of Bison, the GNU Compiler Compiler.

Bison is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

Bison is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Bison; see the file COPYING.  If not, write to
the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  */


#include "system.h"

#if defined (VMS) & !defined (__VMS_POSIX)
#include <ssdef.h>
#define unlink delete
#ifndef XPFILE
#define XPFILE "GNU_BISON:[000000]BISON.SIMPLE"
#endif
#ifndef XPFILE1
#define XPFILE1 "GNU_BISON:[000000]BISON.HAIRY"
#endif
#endif

#if defined (_MSC_VER)
#ifndef XPFILE
#define XPFILE "c:/usr/local/lib/bison.simple"
#endif
#ifndef XPFILE1
#define XPFILE1 "c:/usr/local/lib/bison.hairy"
#endif
#endif

#include <stdio.h>

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#if defined (__DJGPP__)
#define _TAB ((pathconf (NULL, _PC_NAME_MAX) > 12) ? ".tab" : "_tab")
#elif defined (__MSDOS__) || defined (VMS)
#define _TAB "_tab")
#else
#define _TAB ".tab"
#endif

#if defined (__MSDOS__) && !defined (__DJGPP__)
#define NO_CASE_PRESERVE
#endif

#include "files.h"
#include "alloc.h"
#include "gram.h"

FILE *finput = NULL;
FILE *foutput = NULL;
FILE *fdefines = NULL;
FILE *ftable = NULL;
FILE *fattrs = NULL;
FILE *fguard = NULL;
FILE *faction = NULL;
FILE *fparser = NULL;

/* File name specified with -o for the output file, or 0 if no -o.  */
char *spec_outfile;

char *infile;
char *outfile;
char *defsfile;
char *tabfile;
char *attrsfile;
char *guardfile;
char *actfile;
char *tmpattrsfile;
char *tmptabfile;
char *tmpdefsfile;

extern int noparserflag;

extern char	*mktemp();	/* So the compiler won't complain */
extern char	*getenv();
extern void	perror();

char *stringappend PARAMS((char *, int, char *));
void openfiles PARAMS((void));
void open_extra_files PARAMS((void));
FILE *tryopen PARAMS((char *, char *));	/* This might be a good idea */
int tryclose PARAMS((FILE *));
void done PARAMS((int));

extern char *program_name;
extern int verboseflag;
extern int definesflag;
int fixed_outfiles = 0;


char *
stringappend (char *string1, int end1, char *string2)
{
  register char *ostring;
  register char *cp, *cp1;
  register int i;

  cp = string2;  i = 0;
  while (*cp++) i++;

  ostring = NEW2(i+end1+1, char);

  cp = ostring;
  cp1 = string1;
  for (i = 0; i < end1; i++)
    *cp++ = *cp1++;

  cp1 = string2;
  while ((*cp++ = *cp1++))
    ;

  return ostring;
}


/* JF this has been hacked to death.  Nowaday it sets up the file names for
   the output files, and opens the tmp files and the parser */
void
openfiles (void)
{
  char *name_base;
#ifdef __MSDOS__
  register char *cp;
#endif
  char *filename;
  int base_length;
  int short_base_length;

#if defined (VMS) & !defined (__VMS_POSIX)
  char *tmp_base = "sys$scratch:b_";
#else
  char *tmp_base = "/tmp/b.";
#endif
  int tmp_len;

#ifdef __MSDOS__
  tmp_base = getenv ("TMPDIR");

  if (tmp_base == 0);
    tmp_base = getenv ("TEMP");

  if (tmp_base == 0)
    tmp_base = getenv ("TMP");

  if (tmp_base == 0)
    tmp_base = "";
  strlwr (infile);
#endif /* __MSDOS__ */

#if (defined(_WIN32) && !defined(__CYGWIN__))
  tmp_base = getenv ("TEMP");		/* Windows95 defines this ... */
  if (tmp_base == 0)
    tmp_base = getenv ("Temp");		/* ... while NT prefers this */
  if (tmp_base == 0)
    tmp_base = "";
  strlwr (infile);
#endif /* _WIN32 && !__CYGWIN32__ */

#if (defined(unix) || defined(__unix) || defined(__unix__))
  {
    char *tmp_ptr = getenv("TMPDIR");

    if (tmp_ptr != 0)
      tmp_base = stringappend (tmp_ptr, strlen (tmp_ptr), "/b.");
  }
#endif  /* unix || __unix || __unix__ */

  tmp_len = strlen (tmp_base);

  if (spec_outfile)
    {
      /* -o was specified.  The precise -o name will be used for ftable.
	 For other output files, remove the ".c" or ".tab.c" suffix.  */
      name_base = spec_outfile;
#ifdef NO_CASE_PRESERVE
      strlwr (name_base);
#endif /* __MSDOS__ */
      /* BASE_LENGTH includes ".tab" but not ".c".  */
      base_length = strlen (name_base);
      if (!strcmp (name_base + base_length - 2, ".c"))
	base_length -= 2;
      /* SHORT_BASE_LENGTH includes neither ".tab" nor ".c".  */
      short_base_length = base_length;
      if (!strncmp (name_base + short_base_length - 4, ".tab", 4))
	short_base_length -= 4;
      else if (!strncmp (name_base + short_base_length - 4, "_tab", 4))
	short_base_length -= 4;
    }
  else if (spec_file_prefix)
    {
      /* -b was specified.  Construct names from it.  */
      /* SHORT_BASE_LENGTH includes neither ".tab" nor ".c".  */
      short_base_length = strlen (spec_file_prefix);
      /* Count room for `.tab'.  */
      base_length = short_base_length + 4;
      name_base = (char *) xmalloc (base_length + 1);
      /* Append `.tab'.  */
      strcpy (name_base, spec_file_prefix);
      strcat (name_base, _TAB);
#ifdef NO_CASE_PRESERVE
      strlwr (name_base);
#endif
    }
  else
    {
      /* -o was not specified; compute output file name from input
	 or use y.tab.c, etc., if -y was specified.  */

      name_base = fixed_outfiles ? "y.y" : infile;

      /* BASE_LENGTH gets length of NAME_BASE, sans ".y" suffix if any.  */

      base_length = strlen (name_base);
      if (!strcmp (name_base + base_length - 2, ".y"))
	base_length -= 2;
      short_base_length = base_length;

      name_base = stringappend(name_base, short_base_length, _TAB);
      base_length = short_base_length + 4;
    }

  finput = tryopen(infile, "r");

  if (! noparserflag) 
    {
      filename = getenv("BISON_SIMPLE");
#if defined (__MSDOS__)
      /* File doesn't exist in current directory; try in INIT directory.  */
      cp = getenv("INIT");
      if (filename == 0 && cp != NULL)
        {
          filename = xmalloc(strlen(cp) + strlen(PFILE) + 2);
          strcpy(filename, cp);
          cp = filename + strlen(filename);
          *cp++ = '/';
          strcpy(cp, PFILE);
        }
#endif /* __MSDOS__ */
      fparser = tryopen(filename ? filename : PFILE, "r");
    }

  if (verboseflag)
    {
#ifdef __MSDOS__
      outfile = stringappend(name_base, short_base_length, ".out");
#else
      /* We used to use just .out if spec_name_prefix (-p) was used,
	 but that conflicts with Posix.  */
      outfile = stringappend(name_base, short_base_length, ".output");
#endif
      foutput = tryopen(outfile, "w");
    }

  if (noparserflag)
    {
      /* use permanent name for actions file */
      actfile = stringappend(name_base, short_base_length, ".act");
      faction = tryopen(actfile, "w");
    } 

#ifdef __MSDOS__
  if (! noparserflag)
    actfile = mktemp(stringappend(tmp_base, tmp_len, "acXXXXXX"));
  tmpattrsfile = mktemp(stringappend(tmp_base, tmp_len, "atXXXXXX"));
  tmptabfile = mktemp(stringappend(tmp_base, tmp_len, "taXXXXXX"));
  tmpdefsfile = mktemp(stringappend(tmp_base, tmp_len, "deXXXXXX"));
#else
  if (! noparserflag)
    actfile = mktemp(stringappend(tmp_base, tmp_len, "act.XXXXXX"));
  tmpattrsfile = mktemp(stringappend(tmp_base, tmp_len, "attrs.XXXXXX"));
  tmptabfile = mktemp(stringappend(tmp_base, tmp_len, "tab.XXXXXX"));
  tmpdefsfile = mktemp(stringappend(tmp_base, tmp_len, "defs.XXXXXX"));
#endif /* not __MSDOS__ */

  if (! noparserflag)
    faction = tryopen(actfile, "w+");
  fattrs = tryopen(tmpattrsfile,"w+");
  ftable = tryopen(tmptabfile, "w+");

  if (definesflag)
    {
      defsfile = stringappend(name_base, base_length, ".h");
      fdefines = tryopen(tmpdefsfile, "w+");
    }

#if !(defined (__MSDOS__) || (defined(_WIN32) && !defined(__CYGWIN32__)))
  if (! noparserflag)
    unlink(actfile);
  unlink(tmpattrsfile);
  unlink(tmptabfile);
  unlink(tmpdefsfile);
#endif /* __MSDOS__ || (_WIN32 && !__CYGWIN32__) */

	/* These are opened by `done' or `open_extra_files', if at all */
  if (spec_outfile)
    tabfile = spec_outfile;
  else
    tabfile = stringappend(name_base, base_length, ".c");

#ifdef VMS
  attrsfile = stringappend(name_base, short_base_length, "_stype.h");
  guardfile = stringappend(name_base, short_base_length, "_guard.c");
#else
#ifdef __MSDOS__
  attrsfile = stringappend(name_base, short_base_length, ".sth");
  guardfile = stringappend(name_base, short_base_length, ".guc");
#else
  attrsfile = stringappend(name_base, short_base_length, ".stype.h");
  guardfile = stringappend(name_base, short_base_length, ".guard.c");
#endif /* not __MSDOS__ */
#endif /* not VMS */
}



/* open the output files needed only for the semantic parser.
This is done when %semantic_parser is seen in the declarations section.  */

void
open_extra_files (void)
{
  FILE *ftmp;
  int c;
  char *filename;
#ifdef MSDOS
  char *cp;
#endif

  tryclose(fparser);

  if (! noparserflag) 
    {
      filename = (char *) getenv ("BISON_HAIRY");
#if defined (__MSDOS__)
      /* File doesn't exist in current directory; try in INIT directory.  */
      cp = getenv("INIT");
      if (filename == 0 && cp != NULL)
        {
          filename = xmalloc(strlen(cp) + strlen(PFILE1) + 2);
          strcpy(filename, cp);
          cp = filename + strlen(filename);
          *cp++ = '/';
          strcpy(cp, PFILE1);
        }
#endif
      fparser= tryopen(filename ? filename : PFILE1, "r");
    }

		/* JF change from inline attrs file to separate one */
  ftmp = tryopen(attrsfile, "w");
  rewind(fattrs);
  while((c=getc(fattrs))!=EOF)	/* Thank god for buffering */
    putc(c,ftmp);
  tryclose(fattrs);
  fattrs=ftmp;

  fguard = tryopen(guardfile, "w");

}

	/* JF to make file opening easier.  This func tries to open file
	   NAME with mode MODE, and prints an error message if it fails. */
FILE *
tryopen (char *name, char *mode)
{
  FILE	*ptr;

  ptr = fopen(name, mode);
  if (ptr == NULL)
    {
      fprintf(stderr, "%s: ", program_name);
      perror(name);
      done(2);
    }
  return ptr;
}

int
tryclose (FILE *ptr)
{
  int result;

  if (ptr == NULL)
    return 0;

  result = fclose (ptr);
  if (result == EOF)
    {
      fprintf (stderr, "%s: ", program_name);
      perror ("fclose");
      done (2);
    }
  return result;
}

void
done (int k)
{
  tryclose(faction);
  tryclose(fattrs);
  tryclose(fguard);
  tryclose(finput);
  tryclose(fparser);
  tryclose(foutput);

	/* JF write out the output file */
  if (k == 0 && ftable)
    {
      FILE *ftmp;
      register int c;

      ftmp=tryopen(tabfile, "w");
      rewind(ftable);
      while((c=getc(ftable)) != EOF)
        putc(c,ftmp);
      tryclose(ftmp);
      tryclose(ftable);

      if (definesflag)
        {
          ftmp = tryopen(defsfile, "w");
          fflush(fdefines);
          rewind(fdefines);
          while((c=getc(fdefines)) != EOF)
            putc(c,ftmp);
          tryclose(ftmp);
          tryclose(fdefines);
        }
    }

#if defined (VMS) & !defined (__VMS_POSIX)
  if (faction && ! noparserflag)
    delete(actfile);
  if (fattrs)
    delete(tmpattrsfile);
  if (ftable)
    delete(tmptabfile);
  if (k==0) sys$exit(SS$_NORMAL);
  sys$exit(SS$_ABORT);
#else
#if (defined (__MSDOS__) || (defined(_WIN32) && !defined(__CYGWIN32__)))
  if (actfile && ! noparserflag) unlink(actfile);
  if (tmpattrsfile) unlink(tmpattrsfile);
  if (tmptabfile) unlink(tmptabfile);
  if (tmpdefsfile) unlink(tmpdefsfile);
#endif /* MSDOS || (_WIN32 && !__CYGWIN32__) */
  exit(k);
#endif /* not VMS, or __VMS_POSIX */
}
