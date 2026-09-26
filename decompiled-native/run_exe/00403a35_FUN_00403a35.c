// 00403a35 FUN_00403a35 [Global]
// programa: run.exe

undefined4 __cdecl FUN_00403a35(short *param_1)

{
  int iVar1;
  short *psVar2;
  undefined4 uVar3;
  
  if (param_1 != (short *)0x0) {
    iVar1 = FUN_00403689(param_1);
    psVar2 = _malloc(iVar1 * 2 + 2);
    if (psVar2 != (short *)0x0) {
      uVar3 = FUN_00403664(psVar2,param_1);
      return uVar3;
    }
  }
  return 0;
}


