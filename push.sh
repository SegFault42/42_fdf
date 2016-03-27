clear
echo "\033[46mmake fclean\033[0m"
make fclean
echo "Appuyer sur Entrée pour continuer..."
read a
clear
echo "\033[46mgit status\033[0m"
git status
echo "Appuyer sur Entrée pour continuer..."
read a
clear
echo "\033[46mgit add\033[0m"
git add *
echo "\033[46mgit status\033[0m"
git status
echo "Appuyer sur Entrée pour continuer..."
read a
clear
echo "\033[46mgit commit\033[0m"
git commit -m "FDF"
echo "Appuyer sur Entrée pour continuer..."
read a
clear
echo "\033[46mgit push\033[0m"
git push
