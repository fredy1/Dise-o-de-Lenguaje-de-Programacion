cd /dev/env/DJDIR/share

echo "Renaming bison.simple to bison.sim"
if test -f bison.simple; then
  mv bison.simple bison.sim
fi

echo "Renaming bison.hairy to bison.hai"
if test -f bison.hairy; then
  mv bison.hairy bison.hai
fi
echo "Done!"

