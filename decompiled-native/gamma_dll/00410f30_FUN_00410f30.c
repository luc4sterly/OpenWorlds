// 00410f30 FUN_00410f30 [Global]
// programa: gamma.dll

undefined4 __fastcall FUN_00410f30(int *param_1)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  
  bVar3 = true;
  bVar2 = true;
  if (param_1[9] != 0) {
    bVar1 = false;
    if ((uint)param_1[4] < (uint)param_1[5]) {
      iVar4 = (**(code **)(*param_1 + 0x30))(0xffffffff);
      if (iVar4 == -1) {
        bVar1 = true;
      }
    }
    if (!bVar1) {
      bVar2 = false;
    }
  }
  if (!bVar2) {
    iVar4 = FUN_00454f40((undefined4 *)param_1[9]);
    if (iVar4 == 0) {
      bVar3 = false;
    }
  }
  if (bVar3) {
    return 0xffffffff;
  }
  return 0;
}


