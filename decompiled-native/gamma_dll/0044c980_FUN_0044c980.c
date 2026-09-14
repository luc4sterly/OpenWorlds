// 0044c980 FUN_0044c980 [Global]
// programa: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte * __cdecl
FUN_0044c980(int param_1,uint param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,uint param_7)

{
  char cVar1;
  ushort uVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  byte *pbVar10;
  byte *pbVar11;
  byte local_54;
  uint local_50;
  byte local_4c;
  char local_3c [2];
  undefined4 local_3a;
  undefined1 local_14 [2];
  undefined2 local_12;
  
  local_4c = param_5._1_1_;
  local_50 = param_7;
  if (0x1fd < (int)param_7) {
    return (byte *)0x0;
  }
  local_14[0] = 0;
  local_12 = 0x20;
  FUN_00458390(local_14,param_1,param_2,local_3c);
  pcVar6 = (char *)((int)&local_3a + (local_3a >> 0x10 & 0xff) + 3);
  while( true ) {
    if ((local_3a._2_1_ < 2) || (pcVar6 = pcVar6 + -1, *pcVar6 != '0')) break;
    cVar1 = local_3a._2_1_ - 1;
    local_3a._0_3_ = CONCAT12(cVar1,(short)local_3a);
    local_3a = CONCAT22(local_3a._2_2_,(short)local_3a + 1);
  }
  if (local_3a._3_1_ == '0') {
    local_3a = local_3a & 0xffff0000;
  }
  else {
    if (local_3a._3_1_ == 'I') {
      if ((byte)((double)CONCAT44(param_2,param_1) < _DAT_00480968 |
                (byte)((ushort)((ushort)(NAN((double)CONCAT44(param_2,param_1)) ||
                                        NAN(_DAT_00480968)) << 10) >> 8)) == 1) {
        pbVar10 = (byte *)(param_3 + -5);
        if (((&DAT_00482718)[param_5._1_1_] & 0x80) == 0) {
          *(undefined4 *)pbVar10 = DAT_00480940;
          *(undefined1 *)(param_3 + -1) = DAT_00480944;
        }
        else {
          *(undefined4 *)pbVar10 = DAT_00480938;
          *(undefined1 *)(param_3 + -1) = DAT_0048093c;
        }
      }
      else {
        pbVar10 = (byte *)(param_3 + -4);
        if (((&DAT_00482718)[param_5._1_1_] & 0x80) == 0) {
          *(undefined4 *)pbVar10 = DAT_0048094c;
        }
        else {
          *(undefined4 *)pbVar10 = DAT_00480948;
        }
      }
      return pbVar10;
    }
    if (local_3a._3_1_ == 'N') {
      if (local_3c[0] == '\0') {
        pbVar10 = (byte *)(param_3 + -4);
        if (((&DAT_00482718)[param_5._1_1_] & 0x80) == 0) {
          *(undefined4 *)pbVar10 = DAT_00480964;
        }
        else {
          *(undefined4 *)pbVar10 = DAT_00480960;
        }
      }
      else {
        pbVar10 = (byte *)(param_3 + -5);
        if (((&DAT_00482718)[param_5._1_1_] & 0x80) == 0) {
          *(undefined4 *)pbVar10 = DAT_00480958;
          *(undefined1 *)(param_3 + -1) = DAT_0048095c;
        }
        else {
          *(undefined4 *)pbVar10 = DAT_00480950;
          *(undefined1 *)(param_3 + -1) = DAT_00480954;
        }
      }
      return pbVar10;
    }
  }
  bVar3 = local_3a._2_1_;
  uVar2 = (ushort)local_3a._2_1_;
  local_3a = CONCAT22(local_3a._2_2_,(short)local_3a + (uVar2 - 1));
  pbVar10 = (byte *)(param_3 + -1);
  *pbVar10 = 0;
  switch(param_5._1_1_) {
  case 0x45:
  case 0x65:
    goto switchD_0044cb48_caseD_45;
  case 0x46:
  case 0x66:
switchD_0044cb48_caseD_46:
    uVar5 = local_3a >> 0x10 & 0xff;
    iVar4 = (uVar5 - (int)(short)local_3a) + -1;
    if (iVar4 < 0) {
      iVar4 = 0;
    }
    if ((int)local_50 < iVar4) {
      FUN_0044c8b0((int)local_3c,uVar5 - (iVar4 - local_50));
      iVar4 = ((local_3a >> 0x10 & 0xff) - (int)(short)local_3a) + -1;
      if (iVar4 < 0) {
        iVar4 = 0;
      }
    }
    iVar8 = (short)local_3a + 1;
    if (iVar8 < 0) {
      iVar8 = 0;
    }
    if (0x1fd < iVar4 + iVar8) {
      return (byte *)0x0;
    }
    pbVar11 = (byte *)((int)&local_3a + local_3a._2_1_ + 3);
    iVar9 = 0;
    iVar7 = local_50 - iVar4;
    if (0 < iVar7) {
      if (8 < iVar7) {
        do {
          pbVar10[-1] = 0x30;
          pbVar10[-2] = 0x30;
          pbVar10[-3] = 0x30;
          pbVar10[-4] = 0x30;
          pbVar10[-5] = 0x30;
          pbVar10[-6] = 0x30;
          pbVar10[-7] = 0x30;
          pbVar10 = pbVar10 + -8;
          *pbVar10 = 0x30;
          iVar9 = iVar9 + 8;
        } while (iVar9 < iVar7 + -8);
      }
      for (; iVar9 < iVar7; iVar9 = iVar9 + 1) {
        pbVar10 = pbVar10 + -1;
        *pbVar10 = 0x30;
      }
    }
    for (iVar7 = 0; (iVar7 < iVar4 && (iVar7 < (int)(uint)local_3a._2_1_)); iVar7 = iVar7 + 1) {
      pbVar11 = pbVar11 + -1;
      pbVar10 = pbVar10 + -1;
      *pbVar10 = *pbVar11;
    }
    for (; iVar7 < iVar4; iVar7 = iVar7 + 1) {
      pbVar10 = pbVar10 + -1;
      *pbVar10 = 0x30;
    }
    if ((local_50 != 0) || (param_4._3_1_ != '\0')) {
      pbVar10 = pbVar10 + -1;
      *pbVar10 = 0x2e;
    }
    if (iVar8 == 0) {
      pbVar10 = pbVar10 + -1;
      *pbVar10 = 0x30;
    }
    else {
      for (iVar4 = 0; iVar4 < (int)(iVar8 - (uint)local_3a._2_1_); iVar4 = iVar4 + 1) {
        pbVar10 = pbVar10 + -1;
        *pbVar10 = 0x30;
      }
      for (; iVar4 < iVar8; iVar4 = iVar4 + 1) {
        pbVar11 = pbVar11 + -1;
        pbVar10 = pbVar10 + -1;
        *pbVar10 = *pbVar11;
      }
    }
    if (local_3c[0] != '\0') {
      pbVar10[-1] = 0x2d;
      return pbVar10 + -1;
    }
    if (param_4._1_1_ == '\x01') {
      pbVar10[-1] = 0x2b;
      return pbVar10 + -1;
    }
    goto LAB_0044ce51;
  case 0x47:
  case 0x67:
    if ((int)param_7 < (int)(uint)bVar3) {
      FUN_0044c8b0((int)local_3c,param_7);
    }
    if ((-5 < (short)local_3a) && (iVar4 = (int)(short)local_3a, iVar4 < (int)param_7)) {
      if (param_4._3_1_ == '\0') {
        local_50 = (uint)local_3a._2_1_ - (iVar4 + 1);
        if ((int)local_50 < 0) {
          local_50 = 0;
        }
      }
      else {
        local_50 = param_7 - (iVar4 + 1);
      }
      goto switchD_0044cb48_caseD_46;
    }
    if (param_4._3_1_ == '\0') {
      param_7 = (uint)local_3a._2_1_;
    }
    local_50 = param_7 - 1;
    if (param_5._1_1_ == 0x67) {
      local_4c = 0x65;
    }
    else {
      local_4c = 0x45;
    }
switchD_0044cb48_caseD_45:
    if ((int)(local_50 + 1) < (int)(local_3a >> 0x10 & 0xff)) {
      FUN_0044c8b0((int)local_3c,local_50 + 1);
    }
    iVar4 = (int)(short)local_3a;
    local_54 = 0x2b;
    if (iVar4 < 0) {
      iVar4 = -iVar4;
      local_54 = 0x2d;
    }
    for (iVar8 = 0; (iVar4 != 0 || (iVar8 < 2)); iVar8 = iVar8 + 1) {
      pbVar10 = pbVar10 + -1;
      *pbVar10 = (char)iVar4 + (char)(iVar4 / 10) * -10 + 0x30;
      iVar4 = iVar4 / 10;
    }
    pbVar10[-1] = local_54;
    pbVar11 = pbVar10 + -2;
    *pbVar11 = local_4c;
    if (0x1fd < (int)((param_3 - (int)pbVar11) + local_50)) {
      return (byte *)0x0;
    }
    if ((int)(uint)local_3a._2_1_ < (int)(local_50 + 1)) {
      for (iVar4 = (local_50 - local_3a._2_1_) + 1; iVar4 != 0; iVar4 = iVar4 + -1) {
        pbVar11 = pbVar11 + -1;
        *pbVar11 = 0x30;
      }
    }
    uVar5 = (uint)local_3a._2_1_;
    pbVar10 = (byte *)((int)&local_3a + local_3a._2_1_ + 3);
    while (uVar5 = uVar5 - 1, uVar5 != 0) {
      pbVar10 = pbVar10 + -1;
      pbVar11 = pbVar11 + -1;
      *pbVar11 = *pbVar10;
    }
    if ((local_50 != 0) || (param_4._3_1_ != '\0')) {
      pbVar11 = pbVar11 + -1;
      *pbVar11 = 0x2e;
    }
    pbVar10 = pbVar11 + -1;
    *pbVar10 = local_3a._3_1_;
    if (local_3c[0] == '\0') {
      if (param_4._1_1_ == '\x01') {
        pbVar10 = pbVar11 + -2;
        *pbVar10 = 0x2b;
      }
      else {
LAB_0044ce51:
        if (param_4._1_1_ == '\x02') {
          pbVar10 = pbVar10 + -1;
          *pbVar10 = 0x20;
        }
      }
    }
    else {
      pbVar10 = pbVar11 + -2;
      *pbVar10 = 0x2d;
    }
switchD_0044cb48_caseD_48:
    return pbVar10;
  default:
    goto switchD_0044cb48_caseD_48;
  }
}


