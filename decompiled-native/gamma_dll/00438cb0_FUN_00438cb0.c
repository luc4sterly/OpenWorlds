// 00438cb0 FUN_00438cb0 [Global]
// programa: gamma.dll

void __cdecl FUN_00438cb0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  undefined4 uVar6;
  
  iVar1 = param_1[1];
  bVar3 = iVar1 <= (int)param_2[1];
  bVar4 = (int)param_2[1] <= (int)param_3[1];
  bVar5 = bVar3;
  if ((bVar3 != bVar4) && (bVar5 = false, iVar1 <= (int)param_3[1])) {
    bVar5 = true;
  }
  if (((bVar3) && (!bVar4)) && (bVar5)) {
    return;
  }
  if (((!bVar3) && (bVar4)) && (!bVar5)) {
    uVar6 = *param_1;
    *param_1 = *param_2;
    param_1[1] = param_2[1];
    *param_2 = uVar6;
    param_2[1] = iVar1;
    return;
  }
  if (!bVar3) {
    uVar6 = *param_1;
    *param_1 = *param_2;
    param_1[1] = param_2[1];
    *param_2 = uVar6;
    param_2[1] = iVar1;
  }
  if (bVar4) {
    uVar2 = *param_2;
    uVar6 = param_2[1];
    *param_2 = *param_3;
    param_2[1] = param_3[1];
    *param_3 = uVar2;
  }
  else {
    uVar2 = *param_1;
    uVar6 = param_1[1];
    *param_1 = *param_3;
    param_1[1] = param_3[1];
    *param_3 = uVar2;
  }
  param_3[1] = uVar6;
  return;
}


