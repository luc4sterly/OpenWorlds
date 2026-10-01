// 004032c3 FUN_004032c3 [Global]
// program: gdkup.exe

undefined8 __fastcall FUN_004032c3(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  uint in_EAX;
  undefined4 uVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  int extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  uint uVar6;
  undefined8 uVar7;
  
  if ((in_EAX != 0) && (in_EAX < 0xffffffd5)) {
    bVar1 = false;
    uVar6 = in_EAX + 3 & 0xfffffffc;
    (*(code *)PTR_FUN_00408b54)();
    uVar2 = extraout_EDX;
LAB_004032fc:
    do {
      uVar3 = uVar6;
      if (uVar6 < 0xc) {
        uVar3 = 0xc;
      }
      if ((uVar3 <= DAT_00408b30) || (iVar5 = DAT_00408b2c, DAT_00408b2c == 0)) {
        DAT_00408b30 = 0;
        iVar5 = DAT_00408b28;
      }
      while (iVar5 != 0) {
        DAT_00408b2c = iVar5;
        puVar4 = FUN_0040441e();
        if (puVar4 != (uint *)0x0) goto LAB_00403393;
        if (DAT_00408b30 < *(uint *)(extraout_ECX + 0x14)) {
          DAT_00408b30 = *(uint *)(extraout_ECX + 0x14);
        }
        uVar2 = 0;
        iVar5 = *(int *)(extraout_ECX + 8);
      }
      if (!bVar1) {
        uVar7 = FUN_004046d5(0,uVar2);
        uVar2 = (undefined4)((ulonglong)uVar7 >> 0x20);
        if ((int)uVar7 != 0) {
          bVar1 = true;
          goto LAB_004032fc;
        }
      }
      iVar5 = FUN_00404730();
      if (iVar5 == 0) goto LAB_00403393;
      bVar1 = false;
      uVar2 = extraout_EDX_00;
    } while( true );
  }
  uVar2 = 0;
LAB_004033a3:
  return CONCAT44(param_2,uVar2);
LAB_00403393:
  DAT_0040b46c = 0;
  (*(code *)PTR_FUN_00408b5c)();
  uVar2 = extraout_EDX_01;
  goto LAB_004033a3;
}


