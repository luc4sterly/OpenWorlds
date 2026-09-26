// 00403bae FUN_00403bae [Global]
// programa: run.exe

undefined4 __cdecl FUN_00403bae(undefined4 param_1)

{
  int iVar1;
  
  if (DAT_0040bb98 != (code *)0x0) {
    iVar1 = (*DAT_0040bb98)(param_1);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}


