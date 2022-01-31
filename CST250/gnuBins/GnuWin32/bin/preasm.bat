@echo off
setlocal 
set pasmpath="%~dp0%preasm.awk"
gawk -f %pasmpath% %*
