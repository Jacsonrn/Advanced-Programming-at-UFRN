@echo off
setlocal

echo =======================================================
echo      SINCRONIZANDO COM O REPOSITORIO REMOTO
echo =======================================================
echo.

:: Pede uma mensagem de commit
set "commit_message="
set /p commit_message="Digite a mensagem do commit (ou pressione ENTER para uma padrao): "

:: Se a mensagem estiver vazia, usa uma padrao
if not defined commit_message (
    set "commit_message=Atualizacao automatica de arquivos"
)

echo.
echo [1/4] Adicionando todos os arquivos modificados (git add .)...
git add .
if %ERRORLEVEL% NEQ 0 (
    echo [ERRO] Falha ao adicionar arquivos. Verifique o status do Git.
    goto end
)
echo [OK] Arquivos adicionados.
echo.

echo [2/4] Fazendo commit das mudancas (git commit)...
git commit -m "%commit_message%"
echo.

echo [3/4] Enviando para o repositorio remoto principal (git push)...
git push
echo.

echo [4/4] Enviando a subpasta para o repositorio Route-Planner (git subtree push)...
git subtree push --prefix="Projeto 02 - Jacson Arruda Ribeiro" route-planner main
echo [OK] Sincronizacao concluida em ambos os repositorios!

:end
pause