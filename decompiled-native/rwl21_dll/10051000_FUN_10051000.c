// 10051000 FUN_10051000 [Global]
// program: RWL21.DLL

undefined8 __fastcall FUN_10051000(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  iVar1 = *(int *)(*(int *)(param_3 + 0x40) + 0x18);
  iVar2 = *(int *)(*(int *)(param_3 + 0x40) + 0x1c);
  uVar7 = iVar1 - *(int *)(*(int *)(param_3 + 0x44) + 0x18);
  uVar5 = iVar1 - *(int *)(*(int *)(param_3 + 0x3c) + 0x18);
  uVar6 = iVar2 - *(int *)(*(int *)(param_3 + 0x44) + 0x1c);
  uVar8 = iVar2 - *(int *)(*(int *)(param_3 + 0x3c) + 0x1c);
  uVar9 = uVar7 ^ uVar8;
  if ((int)(uVar5 ^ uVar6 ^ uVar9) < 0) {
    return CONCAT44(param_2,uVar9 >> 0x1f);
  }
  lVar3 = (longlong)(int)uVar5 * (longlong)(int)uVar6;
  lVar4 = (longlong)(int)uVar7 * (longlong)(int)uVar8;
  return CONCAT44(param_2,((int)((ulonglong)lVar4 >> 0x20) - (int)((ulonglong)lVar3 >> 0x20)) -
                          (uint)((uint)lVar4 < (uint)lVar3) >> 0x1f);
}


