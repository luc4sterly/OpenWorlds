// 0040d14e FUN_0040d14e [Global]
// program: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0040d14e(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *in_EAX;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  int extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  int extraout_ECX_03;
  undefined4 extraout_ECX_04;
  undefined4 unaff_EBX;
  int iVar9;
  undefined1 local_34 [12];
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  undefined4 *local_18;
  
  local_18 = param_1;
  if (DAT_00439298 != 0) {
    DAT_00439298 = 0;
    FUN_0042bdf7(10,0);
    iVar5 = 0;
    do {
      iVar5 = iVar5 + 1;
    } while (iVar5 < 3);
    (&DAT_00445310)[iVar5] = 0;
  }
  iVar5 = 0x2d4;
  do {
    *(undefined4 *)(DAT_004433c4 + iVar5) = *(undefined4 *)(DAT_004433c4 + 0x2d0 + iVar5);
    *(undefined4 *)(DAT_004433c0 + iVar5) = *(undefined4 *)(DAT_004433c0 + 0x2d0 + iVar5);
    iVar5 = iVar5 + 4;
  } while (iVar5 != 0x874);
  iVar5 = 0x394;
  do {
    *(undefined4 *)(iVar5 + DAT_004433c8) = *(undefined4 *)(iVar5 + 0x2d0 + DAT_004433c8);
    iVar5 = iVar5 + 4;
  } while (iVar5 != 0x5a4);
  iVar5 = 100;
  do {
    *(undefined4 *)(iVar5 + DAT_004433cc) = *(undefined4 *)(iVar5 + 0x2d0 + DAT_004433cc);
    iVar5 = iVar5 + 4;
  } while (iVar5 != 0x874);
  iVar9 = 1;
  iVar5 = 4;
  for (iVar6 = 4; iVar6 <= (DAT_00439294 + -1) * 4; iVar6 = iVar6 + 4) {
    iVar7 = iVar5;
    if (0xb4 < *(int *)((int)&DAT_004452cc + iVar6)) {
      iVar7 = iVar5 + 4;
      iVar9 = iVar9 + 1;
      *(int *)((int)&DAT_004452cc + iVar5) = *(int *)((int)&DAT_004452cc + iVar6) + -0xb4;
    }
    iVar5 = iVar7;
  }
  iVar6 = 0;
  _DAT_00443318 = DAT_0044331c;
  iVar5 = 0x78;
  _DAT_00443328 = DAT_0044332c;
  DAT_00439294 = iVar9;
  do {
    (&DAT_00441290)[iVar6] = (&DAT_00441294)[iVar6] + -0xb4;
    (&DAT_0044129c)[iVar6] = (&DAT_004412a0)[iVar6] + -0xb4;
    (&DAT_00441b18)[iVar6] = (&DAT_00441b1c)[iVar6] + -0xb4;
    (&DAT_00441b24)[iVar6] = (&DAT_00441b28)[iVar6] + -0xb4;
    (&DAT_004452f8)[iVar6] = (&DAT_004452fc)[iVar6] + -0xb4;
    (&DAT_00445304)[iVar6] = (&DAT_00445308)[iVar6] + -0xb4;
    (&DAT_00445310)[iVar6] = (&DAT_00445314)[iVar6];
    (&DAT_0044331c)[iVar6] = (&DAT_00443320)[iVar6];
    (&DAT_004433d0)[iVar6] = (&DAT_004433d4)[iVar6];
    (&DAT_0044332c)[iVar6] = (&DAT_00443330)[iVar6];
    iVar9 = iVar6 * 4;
    do {
      iVar7 = iVar9 + 0xc;
      *(undefined4 *)((int)&DAT_00440f58 + iVar9) = *(undefined4 *)((int)&DAT_00440f5c + iVar9);
      fVar4 = _DAT_00439290;
      iVar9 = iVar7;
    } while (iVar7 != iVar5);
    iVar6 = iVar6 + 1;
    iVar5 = iVar5 + 4;
  } while (iVar6 < 2);
  fVar2 = 0.0;
  fVar3 = (float)_DAT_00435a8c;
  iVar5 = 1;
  do {
    iVar6 = DAT_004433c4;
    fVar1 = *in_EAX;
    in_EAX = in_EAX + 1;
    iVar9 = iVar5 + 1;
    *(float *)(DAT_004433c4 + 0x870 + iVar5 * 4) = fVar1 * fVar3 - fVar4;
    fVar2 = fVar2 + *(float *)(iVar6 + 0x870 + iVar5 * 4);
    iVar5 = iVar9;
  } while (iVar9 < 0xb5);
  if (_DAT_00435a94 < fVar2) {
    _DAT_00439290 = _DAT_00439290 + 1.0;
  }
  if (fVar2 < _DAT_00435a98) {
    _DAT_00439290 = _DAT_00439290 - 1.0;
  }
  FUN_004099fa(0xffffff4c,(float *)(DAT_004433c0 + 0x870),0.4,(float *)&DAT_00439288);
  FUN_0040a377(&DAT_00441290,0x4452cc);
  FUN_00409a49(extraout_ECX,DAT_00439294);
  FUN_0040a76a(extraout_ECX_00,DAT_004433cc + 0x660);
  FUN_0040acc0(extraout_ECX_01,DAT_004433c8 + 0x390);
  FUN_0040951c(&local_1c,0x4385e4,&local_20,&local_24);
  iVar5 = 1;
  do {
    iVar6 = iVar5 + 1;
    FUN_00408ca4(iVar5,DAT_004433c4,*(float *)(&DAT_00442744 + local_1c * 4),
                 *(float *)(&DAT_00442744 + local_20 * 4),local_24,local_34,0x44530c,
                 (int *)&DAT_00443318);
    iVar5 = iVar6;
  } while (iVar6 < 3);
  FUN_0040b910(unaff_EBX,local_1c,&local_28);
  FUN_00409c1a(0x441290,0x443318,0x441b18,0x4452f8);
  FUN_0040c85f(extraout_ECX_02,(float *)(DAT_00441b20 * 4 + DAT_004433c0 + -4));
  FUN_0040b609(&DAT_00440fcc,(float *)(&stack0xfffffd5c + (DAT_00445300 - DAT_00441b20) * 4));
  FUN_0040a569(extraout_ECX_03,(int)&stack0xfffffd5c);
  FUN_0040ae83(extraout_ECX_04,0x440fd0);
  FUN_00409945();
  *param_2 = DAT_0044331c;
  iVar5 = 0;
  param_2[1] = DAT_0044332c;
  *local_18 = DAT_004433d0;
  puVar8 = (undefined4 *)(param_3 + 4);
  do {
    *puVar8 = *(undefined4 *)((int)&DAT_00440f58 + iVar5);
    puVar8 = puVar8 + 1;
    iVar5 = iVar5 + 0xc;
  } while (puVar8 != (undefined4 *)(param_3 + 0x2c));
  return;
}


