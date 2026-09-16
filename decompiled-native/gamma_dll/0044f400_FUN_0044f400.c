// 0044f400 FUN_0044f400 [Global]
// programa: gamma.dll

undefined4 __fastcall FUN_0044f400(int *param_1)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  short sVar4;
  int iVar5;
  
  bVar3 = true;
  bVar2 = true;
  if (param_1[9] != 0) {
    bVar1 = false;
    if ((uint)param_1[4] < (uint)param_1[5]) {
      sVar4 = (**(code **)(*param_1 + 0x30))(0xffff);
      if (sVar4 == -1) {
        bVar1 = true;
      }
    }
    if (!bVar1) {
      bVar2 = false;
    }
  }
  if (!bVar2) {
    iVar5 = FUN_00454f40((undefined4 *)param_1[9]);
    if (iVar5 == 0) {
      bVar3 = false;
    }
  }
  if (bVar3) {
    return 0xffffffff;
  }
  return 0;
}


