// 00459110 FUN_00459110 [Global]
// program: gamma.dll

undefined4 __cdecl FUN_00459110(LPCSTR param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  
  uVar3 = 0;
  bVar2 = (byte)param_2 >> 2 & 3;
  if (bVar2 == 1) {
    uVar3 = 2;
  }
  if (bVar2 == 2) {
    uVar3 = uVar3 | 4;
  }
  if (bVar2 == 3) {
    uVar3 = uVar3 | 1;
  }
  if (((byte)param_2 >> 2 & 4) != 0) {
    uVar3 = uVar3 | 0x100;
  }
  if ((param_2._1_1_ >> 4 & 1) != 0) {
    uVar3 = uVar3 | 0x8000;
  }
  if (((byte)param_2 & 3) == 1) {
    uVar3 = uVar3 | 0x200;
  }
  if (((byte)param_2 & 3) == 2) {
    uVar3 = uVar3 | 0xa00;
  }
  iVar1 = FUN_0044dd00(param_1,uVar3);
  if (iVar1 == -1) {
    return 1;
  }
  *param_3 = iVar1;
  return 0;
}


