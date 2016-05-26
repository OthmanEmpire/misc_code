@ECHO OFF

set SteamAppID=322330
set SteamGameID=322330

cd ..
"%~dp0..\dontstarve_dedicated_server_nullrenderer.exe" -only_update_server_mods
start "Don't Food Together Overworld" /D "%~dp0.." "%~dp0..\dontstarve_dedicated_server_nullrenderer.exe" -skip_update_server_mods -conf_dir myFOODserver -console
start "Don't Food Together Caves"     /D "%~dp0.." "%~dp0..\dontstarve_dedicated_server_nullrenderer.exe" -skip_update_server_mods -conf_dir myKAHFserver -console
