// 0042fbc4 FUN_0042fbc4 [Global]
// programa: sfmain.exe

int __fastcall FUN_0042fbc4(undefined4 *param_1,uint param_2)

{
  ulonglong uVar1;
  int in_EAX;
  int extraout_ECX;
  int extraout_ECX_00;
  uint uVar2;
  int unaff_EBX;
  uint uVar3;
  uint uVar4;
  undefined *puVar5;
  uint uVar6;
  longlong lVar7;
  
  if ((param_2 < 0xa8c0) && (0 < unaff_EBX)) {
    uVar4 = (param_2 + 0x15180) - unaff_EBX;
    uVar6 = (in_EAX + uVar4 / 0x15180) - 1;
  }
  else {
    uVar4 = param_2 - unaff_EBX;
    uVar6 = in_EAX + uVar4 / 0x15180;
  }
  param_1[2] = (int)(((ulonglong)uVar4 % 0x15180) / 0xe10);
  uVar1 = ((ulonglong)uVar4 % 0x15180) % 0xe10;
  param_1[1] = (int)(uVar1 / 0x3c);
  *param_1 = (int)(uVar1 % 0x3c);
  uVar4 = uVar6 / 0x16e;
  uVar3 = uVar6 + uVar4 * -0x16d;
  if (uVar4 != 0) {
    uVar3 = uVar3 - (uVar4 - 1 >> 2);
  }
  lVar7 = FUN_0042fd0e(param_1,uVar4);
  uVar2 = (uint)((ulonglong)lVar7 >> 0x20);
  uVar4 = (int)lVar7 + 0x16d;
  for (; uVar4 <= uVar3; uVar3 = uVar3 - uVar4) {
    uVar2 = uVar2 + 1;
  }
  puVar5 = &DAT_00437ce4;
  *(uint *)(extraout_ECX + 0x14) = uVar2;
  *(uint *)(extraout_ECX + 0x1c) = uVar3;
  lVar7 = FUN_0042fd0e(extraout_ECX,uVar2);
  if ((int)lVar7 != 0) {
    puVar5 = &DAT_00437cfe;
  }
  uVar4 = uVar3 / 0x1f;
  if ((uint)(*(int *)(puVar5 + uVar4 * 2) >> 0x10) <= uVar3) {
    uVar4 = uVar4 + 1;
  }
  *(uint *)(extraout_ECX_00 + 0x10) = uVar4;
  *(uint *)(extraout_ECX_00 + 0xc) = (uVar3 - (int)*(short *)(puVar5 + uVar4 * 2)) + 1;
  *(uint *)(extraout_ECX_00 + 0x18) = (uVar6 + 1) % 7;
  return extraout_ECX_00;
}


