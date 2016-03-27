clear
echo "\033[35mmake fclean\033[0m"
make fclean
echo "\033[32mAppuyer sur Entrée pour continuer...\033[0m"
read a
clear
echo "\033[35mgit status\033[0m"
git status
echo "\033[32mAppuyer sur Entrée pour continuer...\033[0m"
read a
clear
echo "\033[35mgit add\033[0m"
git add *
echo "\033[35mgit status\033[0m"
git status
echo "\033[32mAppuyer sur Entrée pour continuer...\033[0m"
read a
clear
echo "\033[35mgit commit\033[0m"
git commit -m "FDF"
echo "\033[32mAppuyer sur Entrée pour continuer...\033[0m"
read a
clear
echo "\033[35mgit push\033[0m"
git push
