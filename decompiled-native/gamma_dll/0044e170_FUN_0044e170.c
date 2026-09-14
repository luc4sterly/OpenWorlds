// 0044e170 FUN_0044e170 [Global]
// programa: gamma.dll

undefined4 __fastcall FUN_0044e170(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  code *pcVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  undefined1 auStack_d4 [4];
  LPCRITICAL_SECTION local_d0;
  undefined1 *local_b8;
  undefined1 *local_a0;
  undefined1 *local_88;
  undefined1 *local_70;
  undefined1 *local_58;
  undefined1 *local_40;
  undefined1 *local_28;
  undefined1 *local_10;
  
  local_d0 = (LPCRITICAL_SECTION)FUN_0044e130();
  EnterCriticalSection(local_d0);
  if (DAT_0049e1fc == '\0') {
    puVar5 = (undefined4 *)&DAT_0049e1f0;
    pcVar3 = FUN_00410ad0;
    puVar2 = FUN_00412420(&DAT_0049e200,&DAT_00482468);
    FUN_00450830(puVar2,pcVar3,puVar5);
    DAT_0049e1fc = '\x01';
  }
  if (DAT_0049e250 == '\0') {
    puVar5 = (undefined4 *)&DAT_0049e244;
    pcVar3 = FUN_00410ad0;
    puVar2 = FUN_00412420(&DAT_0049e254,&DAT_004824bc);
    FUN_00450830(puVar2,pcVar3,puVar5);
    DAT_0049e250 = '\x01';
  }
  if (DAT_0049e2a4 == '\0') {
    puVar5 = (undefined4 *)&DAT_0049e298;
    pcVar3 = FUN_00410ad0;
    puVar2 = FUN_00412420(&DAT_0049e2a8,&DAT_00482510);
    FUN_00450830(puVar2,pcVar3,puVar5);
    DAT_0049e2a4 = '\x01';
  }
  if (DAT_0049e2f8 == '\0') {
    puVar5 = (undefined4 *)&DAT_0049e2ec;
    puVar4 = &LAB_0044e520;
    puVar2 = FUN_0044ff10(&DAT_0049e2fc,&DAT_00482468);
    FUN_00450830(puVar2,puVar4,puVar5);
    DAT_0049e2f8 = '\x01';
  }
  if (DAT_0049e35c == '\0') {
    puVar5 = (undefined4 *)&DAT_0049e350;
    puVar4 = &LAB_0044e520;
    puVar2 = FUN_0044ff10(&DAT_0049e360,&DAT_004824bc);
    FUN_00450830(puVar2,puVar4,puVar5);
    DAT_0049e35c = '\x01';
  }
  if (DAT_0049e3c0 == '\0') {
    puVar5 = (undefined4 *)&DAT_0049e3b4;
    puVar4 = &LAB_0044e520;
    puVar2 = FUN_0044ff10(&DAT_0049e3c4,&DAT_00482510);
    FUN_00450830(puVar2,puVar4,puVar5);
    DAT_0049e3c0 = '\x01';
  }
  iVar1 = DAT_0049fe0c;
  DAT_0049fe0c = DAT_0049fe0c + 1;
  if (iVar1 == 0) {
    local_b8 = auStack_d4;
    FUN_00411ef0(&DAT_0049f9ac,1,0x49e200);
    local_a0 = auStack_d4;
    FUN_0044ef30(&DAT_0049eda8,1,0x49e254);
    local_88 = auStack_d4;
    FUN_0044ef30(&DAT_0049ed60,1,0x49e2a8);
    local_70 = auStack_d4;
    FUN_0044ef30(&DAT_0049ed18,1,0x49e2a8);
    *(undefined **)(DAT_0049f9b0 + 0x34) = &DAT_0049eda8;
    *(undefined **)(DAT_0049ed64 + 0x34) = &DAT_0049eda8;
    *(ushort *)(DAT_0049ed64 + 0x30) = *(ushort *)(DAT_0049ed64 + 0x30) | 0x2000;
    *(undefined **)(DAT_0049ed1c + 0x34) = &DAT_0049eda8;
    local_58 = auStack_d4;
    FUN_0044ee40(&DAT_0049fa14,1,0x49e2fc);
    local_40 = auStack_d4;
    FUN_0044f270(&DAT_0049f2b8,1,0x49e360);
    local_28 = auStack_d4;
    FUN_0044f270(&DAT_0049f348,1,0x49e3c4);
    local_10 = auStack_d4;
    FUN_0044f270(&DAT_0049f300,1,0x49e3c4);
    *(undefined **)(DAT_0049fa18 + 0x34) = &DAT_0049f2b8;
    *(undefined **)(DAT_0049f34c + 0x34) = &DAT_0049f2b8;
    *(ushort *)(DAT_0049f34c + 0x30) = *(ushort *)(DAT_0049f34c + 0x30) | 0x2000;
    *(undefined **)(DAT_0049f304 + 0x34) = &DAT_0049f2b8;
    (**(code **)(DAT_0049e200 + 8))(0,0);
    (**(code **)(DAT_0049e254 + 8))(0,0);
    (**(code **)(DAT_0049e2a8 + 8))(0,0);
    (**(code **)(DAT_0049e2fc + 8))(0,0);
    (**(code **)(DAT_0049e360 + 8))(0,0);
    (**(code **)(DAT_0049e3c4 + 8))(0,0);
  }
  LeaveCriticalSection(local_d0);
  return param_1;
}


