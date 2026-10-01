// 00403ad7 FUN_00403ad7 [Global]
// program: sfmain.exe

void __fastcall FUN_00403ad7(undefined2 *param_1,short param_2)

{
  short *in_EAX;
  int iVar1;
  int iVar2;
  int iVar3;
  undefined2 *extraout_ECX;
  undefined2 *puVar4;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  undefined4 extraout_ECX_05;
  undefined4 uVar5;
  short unaff_BX;
  short sVar6;
  
  if ((param_2 < 0) || (puVar4 = param_1, 7 < param_2)) {
    FUN_0042b978();
    puVar4 = extraout_ECX;
  }
  iVar1 = FUN_00407d4c(puVar4,unaff_BX);
  iVar2 = FUN_00407d4c(extraout_ECX_00,1);
  FUN_00407ffe(extraout_ECX_01,(int)(short)iVar2);
  iVar2 = 0xd;
  uVar5 = extraout_ECX_02;
  while (iVar2 = iVar2 + -1, iVar2 != -1) {
    if ((7 < *in_EAX) || (*in_EAX < 0)) {
      FUN_0042b978();
      uVar5 = extraout_ECX_03;
    }
    sVar6 = *in_EAX * 2 + -7;
    in_EAX = in_EAX + 1;
    if ((7 < sVar6) || (sVar6 < -7)) {
      FUN_0042b978();
      uVar5 = extraout_ECX_04;
    }
    iVar3 = FUN_00407f9e(uVar5,(int)(short)iVar1);
    *param_1 = (short)iVar3;
    param_1 = param_1 + 1;
    uVar5 = extraout_ECX_05;
  }
  return;
}


