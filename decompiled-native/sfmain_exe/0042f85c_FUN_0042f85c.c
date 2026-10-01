// 0042f85c FUN_0042f85c [Global]
// program: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 * __fastcall FUN_0042f85c(undefined4 param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  byte *pbVar2;
  undefined1 *puVar3;
  undefined4 extraout_ECX;
  int extraout_ECX_00;
  int iVar4;
  short *psVar5;
  char cVar6;
  undefined8 uVar7;
  int local_bc;
  short local_b8 [40];
  int local_68;
  short local_64 [34];
  undefined4 uStack_20;
  int local_1c;
  int in_stack_ffffffec;
  
  uVar7 = FUN_00432324(param_1,param_2);
  if ((int)uVar7 != 0) {
    _DAT_0043e914 = 0;
    uStack_20._0_2_ = 0xf88e;
    uStack_20._2_2_ = 0x42;
    pbVar2 = FUN_0042f8c9(extraout_ECX,&DAT_0043e918);
    puVar3 = (undefined1 *)CONCAT22((short)((uint)pbVar2 >> 0x10),CONCAT11(*pbVar2,(char)pbVar2));
    if (*pbVar2 == 0) {
      DAT_0043e937 = 0;
    }
    else {
      _DAT_0043e914 = 1;
      local_1c = DAT_0043e90c + -0xe10;
      uStack_20._0_2_ = 0xfb1c;
      uStack_20._2_2_ = 0x42;
      pbVar2 = FUN_0042f8c9(pbVar2,&DAT_0043e937);
      DAT_0043e910 = DAT_0043e90c - local_1c;
      iVar4 = local_1c;
      if (*pbVar2 == 0x2c) {
        uStack_20._0_2_ = 0xfb43;
        uStack_20._2_2_ = 0x42;
        pbVar2 = (byte *)FUN_0042f9f2(local_1c,0x43e8c4);
        iVar4 = extraout_ECX_00;
      }
      puVar3 = (undefined1 *)(uint)*pbVar2;
      if (puVar3 == (undefined1 *)0x2c) {
        uStack_20._0_2_ = 0xfb5b;
        uStack_20._2_2_ = 0x42;
        FUN_0042f9f2(iVar4,0x43e8e8);
        DAT_0043e8f0 = DAT_0043e8f0 - DAT_0043e910 / 0xe10;
        DAT_0043e8ec = DAT_0043e8ec -
                       (int)((longlong)
                             ((ulonglong)(uint)((int)((longlong)DAT_0043e910 / 0x3c) >> 0x1f) <<
                              0x20 | (longlong)DAT_0043e910 / 0x3c & 0xffffffffU) % 0x3c);
        puVar3 = (undefined1 *)(DAT_0043e910 / 0x3c);
        DAT_0043e8e8 = DAT_0043e8e8 - DAT_0043e910 % 0x3c;
      }
    }
    return puVar3;
  }
  puVar3 = (undefined1 *)
           CONCAT22((short)((ulonglong)uVar7 >> 0x10),CONCAT11(DAT_0043e95e,(char)uVar7));
  if (((DAT_0043e95e & 1) == 0) || ((DAT_0043e95e & 2) == 0)) {
    DAT_0043e95e = DAT_0043e95e | 2;
    puVar1 = (undefined1 *)GetTimeZoneInformation((LPTIME_ZONE_INFORMATION)&local_bc);
    puVar3 = (undefined1 *)0x0;
    if (puVar1 != (undefined1 *)0x0) {
      if (puVar1 < (undefined1 *)0x2) {
        _DAT_0043e914 = 0;
      }
      else {
        if (puVar1 != (undefined1 *)0x2) {
          return puVar1;
        }
        _DAT_0043e914 = 1;
        DAT_0043e910 = in_stack_ffffffec * -0x3c;
      }
      cVar6 = ' ';
      DAT_0043e90c = (local_68 + local_bc) * 0x3c;
      puVar3 = &DAT_0043e918;
      for (psVar5 = local_b8; *psVar5 != 0; psVar5 = psVar5 + 1) {
        if (cVar6 == ' ') {
          *puVar3 = (char)*psVar5;
          puVar3 = puVar3 + 1;
        }
        cVar6 = (char)*psVar5;
      }
      cVar6 = ' ';
      *puVar3 = 0;
      puVar3 = &DAT_0043e937;
      for (psVar5 = local_64; *psVar5 != 0; psVar5 = psVar5 + 1) {
        if (cVar6 == ' ') {
          *puVar3 = (char)*psVar5;
          puVar3 = puVar3 + 1;
        }
        cVar6 = (char)*psVar5;
      }
      *puVar3 = 0;
    }
  }
  return puVar3;
}


