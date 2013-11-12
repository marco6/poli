#punto 1
find / -name "*.exe" -executable -size +1024c
#punto 2
find / -name "*.c" -size +100c
#punto 3
find / -name "*a*A*" -o -name "*A*a*" -exec tail -3 '{}' \;
#punto 4
find / -mindepth 3 -maxdepth 5 -regex ".\\{4\\}" -exec wc -m '{}' \; 
find / -mindepth 3 -maxdepth 5 -regex ".\\{4\\}" -exec wc -l '{}' \;  
#punto 5
find / -name "A*zzz*.???"
#punto 6
find / -path "*/bin" -exec ls '{}' \;
#punto 7
find / -group marco ! -user marco -name "*.c"
#punto 8
