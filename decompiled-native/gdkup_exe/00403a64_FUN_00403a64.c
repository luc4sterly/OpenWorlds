// 00403a64 FUN_00403a64 [Global]
// program: gdkup.exe

undefined8 __fastcall FUN_00403a64(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined *puVar3;
  undefined4 *extraout_ECX;
  undefined4 *extraout_ECX_00;
  int extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 *puVar4;
  undefined4 extraout_EDX;
  uint uVar5;
  undefined8 uVar6;
  
  (*(code *)PTR_FUN_00408b4c)();
  if (DAT_0040b460 == (undefined4 *)0x0) {
    for (puVar3 = &DAT_00408bc4; puVar3 < &DAT_00408dcc; puVar3 = puVar3 + 0x1a) {
      if ((puVar3[0xc] & 3) == 0) {
        uVar6 = FUN_004032c3(puVar3,extraout_EDX);
        uVar2 = (undefined4)((ulonglong)uVar6 >> 0x20);
        puVar1 = (undefined4 *)uVar6;
        puVar4 = extraout_ECX;
        if (puVar1 == (undefined4 *)0x0) goto LAB_00403b04;
        uVar5 = 3;
        goto LAB_00403ad9;
      }
    }
    uVar5 = 0x4003;
    uVar6 = FUN_004032c3(puVar3,extraout_EDX);
    uVar2 = (undefined4)((ulonglong)uVar6 >> 0x20);
    puVar1 = (undefined4 *)uVar6;
    puVar4 = extraout_ECX_00;
    if (puVar1 == (undefined4 *)0x0) {
LAB_00403b04:
      FUN_00403848(puVar4,uVar2);
      (*(code *)PTR_FUN_00408b50)();
      uVar2 = 0;
      goto LAB_00403b16;
    }
    puVar4 = puVar1 + 2;
  }
  else {
    puVar4 = (undefined4 *)DAT_0040b460[1];
    uVar5 = (uint)((ushort)puVar4[3] & 0x4003 | 3);
    puVar1 = DAT_0040b460;
    DAT_0040b460 = (undefined4 *)*DAT_0040b460;
  }
LAB_00403ad9:
  FUN_00402980(puVar4,0);
  *(uint *)(extraout_ECX_01 + 0xc) = uVar5;
  puVar1[1] = extraout_ECX_01;
  *puVar1 = DAT_0040b464;
  DAT_0040b464 = puVar1;
  (*(code *)PTR_FUN_00408b50)();
  uVar2 = extraout_ECX_02;
LAB_00403b16:
  return CONCAT44(param_2,uVar2);
}


