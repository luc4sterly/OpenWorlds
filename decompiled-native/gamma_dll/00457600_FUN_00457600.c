// 00457600 FUN_00457600 [Global]
// programa: gamma.dll

void __cdecl FUN_00457600(int param_1,uint *param_2)

{
  uint uVar1;
  short sVar2;
  ulonglong uVar3;
  longlong lVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  
  if (param_2 == (uint *)0x0) {
    return;
  }
  param_2[8] = 0xffffffff;
  uVar8 = (param_1 + 0x83aa7e80U) / 0x15180;
  uVar1 = (param_1 + 0x83aa7e80U) % 0x15180;
  lVar4 = (ulonglong)(uVar8 + 1) * 0x49249249;
  param_2[6] = uVar8 + 1 +
               ((int)((ulonglong)lVar4 >> 0x20) + (uint)(0xb6db6db6 < (uint)lVar4) >> 1) * -7;
  uVar9 = 0;
  while( true ) {
    iVar5 = FUN_004574d0(uVar9);
    if (iVar5 == 0) {
      uVar6 = 0x16d;
    }
    else {
      uVar6 = 0x16e;
    }
    if (uVar8 < uVar6) break;
    uVar8 = uVar8 - uVar6;
    uVar9 = uVar9 + 1;
  }
  param_2[5] = uVar9;
  param_2[7] = uVar8;
  uVar6 = 0;
  iVar7 = FUN_004574d0(uVar9);
  iVar5 = iVar7 * 0xd;
  while ((uint)(int)*(short *)(&DAT_00482a1a + iVar5 * 2) <= uVar8) {
    iVar5 = iVar5 + 1;
    uVar6 = uVar6 + 1;
  }
  sVar2 = *(short *)(&DAT_00482a18 + (iVar7 * 0xd + uVar6) * 2);
  param_2[4] = uVar6;
  param_2[3] = (uVar8 - (int)sVar2) + 1;
  param_2[2] = uVar1 / 0xe10;
  uVar3 = (ulonglong)uVar1 % 0xe10;
  param_2[1] = (uint)(uVar3 / 0x3c);
  *param_2 = (uint)uVar3 % 0x3c;
  return;
}


