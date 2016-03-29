clear
echo "\033[35mmake fclean\033[0m"
make fclean
echo "\033[41mAppuyer sur Entrée pour git status...\033[0m"
read a
clear
echo "\033[35mgit status\033[0m"
git status
echo "\033[41mAppuyer sur Entrée pour git add...\033[0m"
read a
clear
echo "\033[35mgit add\033[0m"
git add *
echo "\033[35mgit status\033[0m"
git status
echo "\033[41mAppuyer sur Entrée pour git commit...\033[0m"
read a
clear
echo "\033[35mgit commit\033[0m"
git commit -m "FDF"
echo "\033[41mAppuyer sur Entrée pour git push...\033[0m"
read a
clear
echo "\033[35mgit push\033[0m"
git push
open ~/Desktop/bBltMFv3copy.jpg
