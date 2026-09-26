// 004015e5 FUN_004015e5 [Global]
// programa: run.exe

int __cdecl FUN_004015e5(PCNZWCH param_1,int param_2)

{
  short sVar1;
  LPCWSTR pWVar2;
  uint uVar3;
  int *piVar4;
  
  pWVar2 = (LPCWSTR)*DAT_0040ba68;
  piVar4 = DAT_0040ba68;
  while( true ) {
    if (pWVar2 == (LPCWSTR)0x0) {
      return -((int)piVar4 - (int)DAT_0040ba68 >> 2);
    }
    uVar3 = FUN_004039d7(param_1,pWVar2,param_2);
    if ((uVar3 == 0) && ((sVar1 = *(short *)(*piVar4 + param_2 * 2), sVar1 == 0x3d || (sVar1 == 0)))
       ) break;
    pWVar2 = (LPCWSTR)piVar4[1];
    piVar4 = piVar4 + 1;
  }
  return (int)piVar4 - (int)DAT_0040ba68 >> 2;
}


