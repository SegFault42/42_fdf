clear
echo "\033[36mmake fclean\033[0m"
make fclean
echo "Appuyer sur Entrée pour continuer..."
read a
clear
echo "\033[36mgit status\033[0m"
git status
echo "Appuyer sur Entrée pour continuer..."
read a
clear
echo "\033[36mgit add\033[0m"
git add *
echo "\033[36mgit status\033[0m"
git status
echo "Appuyer sur Entrée pour continuer..."
read a
clear
echo "\033[36mgit commit\033[0m"
git commit -m "FDF"
echo "Appuyer sur Entrée pour continuer..."
read a
clear
echo "\033[36mgit push\033[0m"
git push
