// 00410c90 FUN_00410c90 [Global]
// programa: gamma.dll

uint __fastcall FUN_00410c90(int *param_1)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = (**(code **)(*param_1 + 0x20))();
  if (iVar2 == -1) {
    uVar3 = 0xffffffff;
  }
  else {
    pbVar1 = (byte *)param_1[2];
    param_1[2] = param_1[2] + 1;
    uVar3 = (uint)*pbVar1;
  }
  return uVar3;
}


