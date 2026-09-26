// 0042ba46 FUN_0042ba46 [Global]
// programa: sfmain.exe

undefined8 __fastcall FUN_0042ba46(undefined4 param_1,undefined4 param_2)

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
    (*(code *)PTR_FUN_0043e808)();
    uVar2 = extraout_EDX;
LAB_0042ba7f:
    do {
      uVar3 = uVar6;
      if (uVar6 < 0xc) {
        uVar3 = 0xc;
      }
      if ((uVar3 <= DAT_0043e52c) || (iVar5 = DAT_0043e528, DAT_0043e528 == 0)) {
        DAT_0043e52c = 0;
        iVar5 = DAT_0043e524;
      }
      while (iVar5 != 0) {
        DAT_0043e528 = iVar5;
        puVar4 = FUN_0042d592();
        if (puVar4 != (uint *)0x0) goto LAB_0042bb16;
        if (DAT_0043e52c < *(uint *)(extraout_ECX + 0x14)) {
          DAT_0043e52c = *(uint *)(extraout_ECX + 0x14);
        }
        uVar2 = 0;
        iVar5 = *(int *)(extraout_ECX + 8);
      }
      if (!bVar1) {
        uVar7 = FUN_0042d849(0,uVar2);
        uVar2 = (undefined4)((ulonglong)uVar7 >> 0x20);
        if ((int)uVar7 != 0) {
          bVar1 = true;
          goto LAB_0042ba7f;
        }
      }
      iVar5 = FUN_0042d8a4();
      if (iVar5 == 0) goto LAB_0042bb16;
      bVar1 = false;
      uVar2 = extraout_EDX_00;
    } while( true );
  }
  uVar2 = 0;
LAB_0042bb26:
  return CONCAT44(param_2,uVar2);
LAB_0042bb16:
  DAT_004e57b4 = 0;
  (*(code *)PTR_FUN_0043e810)();
  uVar2 = extraout_EDX_01;
  goto LAB_0042bb26;
}


