@echo off
echo ========================================================
echo COMPILANDO O PROJETO SUPTANQUES (SERVIDOR E TERMINAL)
echo ========================================================
echo.

echo [1/2] Compilando o Servidor...
g++ -o servidor.exe supservidor_main.cpp supservidor.cpp tanques.cpp supdados.cpp mysocket.cpp -static -static-libgcc -static-libstdc++ -lws2_32 -std=c++11 -D_WIN32_WINNT=0x0601
if %errorlevel% neq 0 (
    echo [ERRO] Falha ao compilar o servidor.
) else (
    echo [OK] Servidor compilado com sucesso! (servidor.exe)
)
echo.

echo [2/2] Compilando o Cliente (Modo Terminal)...
g++ -o cliente_term.exe supcliente_main_term.cpp supcliente_term.cpp supcliente.cpp supdados.cpp mysocket.cpp -static -static-libgcc -static-libstdc++ -lws2_32 -std=c++11 -D_WIN32_WINNT=0x0601
if %errorlevel% neq 0 (
    echo [ERRO] Falha ao compilar o cliente terminal.
) else (
    echo [OK] Cliente compilado com sucesso! (cliente_term.exe)
)
echo.

echo Pressione qualquer tecla para sair...
pause >nul
