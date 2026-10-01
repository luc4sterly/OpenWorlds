// 0044bf00 FUN_0044bf00 [Global]
// program: gamma.dll

undefined8 __fastcall
FUN_0044bf00(undefined4 param_1,undefined4 param_2,int param_3,int *param_4,uint *param_5)

{
  bool bVar1;
  undefined2 uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  uint uVar6;
  undefined3 uVar7;
  uint uVar8;
  undefined4 local_20;
  undefined4 local_1c;
  uint local_18;
  uint local_14;
  
  uVar6 = local_1c;
  local_20 = 1;
  uVar7 = (undefined3)(local_1c >> 8);
  local_1c = local_1c & 0xffffff00;
  uVar3 = local_1c;
  local_18 = 0;
  local_14 = 0;
  pcVar4 = (char *)(param_3 + 1);
  uVar8 = (uint)*pcVar4;
  local_1c._2_2_ = SUB42(uVar6,2);
  if (uVar8 == 0x25) {
    local_1c = (uint)CONCAT21(local_1c._2_2_,*pcVar4) << 8;
    *param_5 = 1;
    param_5[1] = local_1c;
    param_5[2] = 0;
    param_5[3] = 0;
    return CONCAT44(param_2,param_3 + 2);
  }
  while( true ) {
    bVar1 = true;
    uVar2 = local_20._2_2_;
    switch(uVar8) {
    case 0x20:
      if (local_20._1_1_ != '\x01') {
        local_20._0_2_ = CONCAT11(2,(char)local_20);
        local_20 = CONCAT22(uVar2,(ushort)local_20);
      }
      break;
    default:
      bVar1 = false;
      break;
    case 0x23:
      local_20 = CONCAT13(1,(undefined3)local_20);
      break;
    case 0x2b:
      local_20._0_2_ = CONCAT11(1,(char)local_20);
      local_20 = CONCAT22(uVar2,(ushort)local_20);
      break;
    case 0x2d:
      local_20 = (uint)local_20._1_3_ << 8;
      break;
    case 0x30:
      if ((char)local_20 != '\0') {
        local_20 = CONCAT31(local_20._1_3_,2);
      }
    }
    if (!bVar1) break;
    pcVar4 = pcVar4 + 1;
    uVar8 = (uint)*pcVar4;
  }
  if (uVar8 == 0x2a) {
    *param_4 = *param_4 + 4;
    local_18 = *(uint *)(*param_4 + -4);
    uVar6 = 10;
    if ((int)local_18 < 0) {
      local_20 = local_20 & 0xffffff00;
      uVar6 = -local_18;
      local_18 = uVar6;
    }
    pcVar4 = pcVar4 + 1;
    uVar8 = (uint)*pcVar4;
  }
  else {
    while (uVar6 = uVar8 & 0xff, ((&DAT_00482718)[uVar6] & 0x10) != 0) {
      local_18 = local_18 * 10 + (uVar8 - 0x30);
      pcVar4 = pcVar4 + 1;
      uVar8 = (uint)*pcVar4;
    }
  }
  if (0x1fd < (int)local_18) {
    local_1c = CONCAT22(local_1c._2_2_,0xff00);
    *param_5 = local_20;
    param_5[1] = local_1c;
    param_5[2] = local_18;
    param_5[3] = 0;
    return CONCAT44(uVar6,pcVar4 + 1);
  }
  pcVar5 = pcVar4;
  if (uVar8 == 0x2e) {
    local_20._0_3_ = CONCAT12(1,(ushort)local_20);
    pcVar5 = pcVar4 + 1;
    uVar8 = (uint)*pcVar5;
    if (uVar8 == 0x2a) {
      *param_4 = *param_4 + 4;
      local_14 = *(uint *)(*param_4 + -4);
      if ((int)local_14 < 0) {
        local_20 = CONCAT13(local_20._3_1_,(uint3)(ushort)local_20);
      }
      pcVar5 = pcVar4 + 2;
      uVar8 = (uint)*pcVar5;
    }
    else {
      while (((&DAT_00482718)[uVar8 & 0xff] & 0x10) != 0) {
        local_14 = local_14 * 10 + (uVar8 - 0x30);
        pcVar5 = pcVar5 + 1;
        uVar8 = (uint)*pcVar5;
      }
    }
  }
  bVar1 = true;
  if (uVar8 == 0x4c) {
    local_1c = CONCAT31(uVar7,5);
  }
  else if (uVar8 == 0x68) {
    local_1c = CONCAT31(uVar7,2);
    if (pcVar5[1] == 'h') {
      local_1c = CONCAT31(uVar7,1);
      pcVar5 = pcVar5 + 1;
      uVar8 = (uint)*pcVar5;
    }
  }
  else if (uVar8 == 0x6c) {
    local_1c = CONCAT31(uVar7,3);
    if (pcVar5[1] == 'l') {
      local_1c = CONCAT31(uVar7,4);
      pcVar5 = pcVar5 + 1;
      uVar8 = (uint)*pcVar5;
    }
  }
  else {
    bVar1 = false;
    local_1c = uVar3;
  }
  if (bVar1) {
    pcVar5 = pcVar5 + 1;
    uVar8 = (uint)*pcVar5;
  }
  uVar2 = local_1c._2_2_;
  local_1c._0_2_ = CONCAT11((char)uVar8,(char)local_1c);
  uVar7 = (undefined3)(uVar8 >> 8);
  switch(uVar8) {
  case 0x41:
  case 0x61:
    if (local_20._2_1_ == '\0') {
      local_14 = 0xd;
    }
    uVar8 = CONCAT31(uVar7,(char)local_1c);
    if ((((char)local_1c != '\x02') && ((char)local_1c != '\x04')) && ((char)local_1c != '\x01'))
    goto LAB_0044c222;
    break;
  case 0x45:
  case 0x65:
    goto switchD_0044c0ec_caseD_45;
  case 0x46:
  case 0x66:
    if (((char)local_1c != '\x02') && ((char)local_1c != '\x04')) {
      if (local_20._2_1_ == '\0') {
        local_14 = 6;
      }
      goto LAB_0044c222;
    }
    break;
  case 0x47:
  case 0x67:
    if (local_14 == 0) {
      local_14 = 1;
    }
switchD_0044c0ec_caseD_45:
    if ((((char)local_1c != '\x02') && ((char)local_1c != '\x04')) && ((char)local_1c != '\x01')) {
      if (local_20._2_1_ == '\0') {
        local_14 = 6;
      }
      goto LAB_0044c222;
    }
    break;
  case 0x58:
  case 100:
  case 0x69:
  case 0x6f:
  case 0x75:
  case 0x78:
    if ((char)local_1c != '\x05') {
      if (local_20._2_1_ == '\0') {
        local_14 = 1;
      }
      else if ((char)local_20 == '\x02') {
        local_20 = CONCAT31(local_20._1_3_,1);
      }
      goto LAB_0044c222;
    }
    break;
  case 99:
    if ((char)local_1c == '\x03') {
      local_1c = CONCAT31(local_1c._1_3_,6);
      goto LAB_0044c222;
    }
    if (local_20._2_1_ == '\0') goto joined_r0x0044c212;
    break;
  case 0x6e:
    if ((char)local_1c != '\x05') goto LAB_0044c222;
    break;
  case 0x70:
    local_1c = CONCAT22(uVar2,0x7800);
    local_20 = CONCAT13(1,(undefined3)local_20);
    local_1c = CONCAT31(local_1c._1_3_,3);
    local_14 = 8;
    goto LAB_0044c222;
  case 0x73:
    uVar8 = CONCAT31(uVar7,(char)local_1c);
    if ((char)local_1c == '\x03') {
      local_1c = CONCAT31(local_1c._1_3_,6);
      goto LAB_0044c222;
    }
joined_r0x0044c212:
    if ((char)local_1c == '\0') goto LAB_0044c222;
  }
  local_1c._0_2_ = CONCAT11(0xff,(char)local_1c);
  local_1c = CONCAT22(uVar2,(undefined2)local_1c);
LAB_0044c222:
  *param_5 = local_20;
  param_5[1] = local_1c;
  param_5[2] = local_18;
  param_5[3] = local_14;
  return CONCAT44(uVar8,pcVar5 + 1);
}


