// 0041ba30 _Java_NET_worlds_scape_Portal_prerender@12 [Global]
// programa: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _Java_NET_worlds_scape_Portal_prerender_12(int *param_1,undefined4 param_2,undefined4 param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  LPVOID pvVar10;
  int iVar11;
  bool bVar12;
  float10 fVar13;
  float10 fVar14;
  float10 fVar15;
  int local_fc;
  int local_f8;
  int local_ec;
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  float local_1c;
  float local_18;
  float local_14;
  
                    /* 0x1ba30  264  _Java_NET_worlds_scape_Portal_prerender@12 */
  iVar3 = FUN_00412cf0(param_1,param_2);
  if (iVar3 == 0) {
    FUN_00402800(s_nPortal_00470780,0x1e9);
  }
  uVar4 = FUN_004144e0(param_1,param_3);
  if ((uVar4 & 4) == 0) {
    FUN_00419d60(iVar3,1);
    return;
  }
  uVar5 = FUN_00412d20(param_1,param_2);
  iVar6 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_00489600);
  if (iVar6 != 2) {
    if ((iVar6 == -1) && ((uVar5 & 0x40000) == 0)) {
      FUN_00412800(param_1,param_2,DAT_00489618);
      iVar3 = (**(code **)(*param_1 + 0x3c))(param_1);
      if (iVar3 == 0) {
        return;
      }
      return;
    }
    return;
  }
  if ((uVar5 & 1) == 0) {
    return;
  }
  if (DAT_00489628 == '\0') {
    DAT_00489628 = '\x01';
    DAT_00489624 = 0;
  }
  if (10 < DAT_00489624) {
    return;
  }
  DAT_00489624 = DAT_00489624 + 1;
  iVar6 = FUN_004144b0(param_1,param_3);
  if (iVar6 == 0) {
    DAT_00489624 = DAT_00489624 + -1;
    return;
  }
  iVar7 = FUN_0041b3b0(iVar6,iVar3);
  if (iVar7 != 0) {
    DAT_00489624 = DAT_00489624 + -1;
    return;
  }
  local_88 = 0;
  local_8c = 0;
  local_94 = 0;
  local_90 = 0;
  FUN_004192e0(iVar6,&local_94,&local_90,&local_8c,&local_88);
  local_80 = 0.0;
  local_84 = 0.0;
  FUN_00419330(iVar6,&local_84,&local_80);
  local_78 = 0.0;
  local_7c = 0.0;
  FUN_00419290(iVar6,&local_7c,&local_78);
  local_68 = 0;
  local_6c = 0;
  local_74 = 0;
  local_70 = 0;
  FUN_0041b670(iVar3,iVar6,&local_74,&local_70,&local_6c,&local_68);
  if ((((local_74 + local_6c < 1) || (local_8c <= local_74)) || (local_70 + local_68 < 1)) ||
     (local_88 <= local_70)) {
    DAT_00489624 = DAT_00489624 + -1;
    return;
  }
  if (local_74 < 0) {
    local_6c = local_6c + local_74;
    local_74 = 0;
  }
  if (local_70 < 0) {
    local_68 = local_68 + local_70;
    local_70 = 0;
  }
  if (local_8c < local_74 + local_6c) {
    local_6c = local_8c - local_74;
  }
  if (local_88 < local_70 + local_68) {
    local_68 = local_88 - local_70;
  }
  if ((0 < local_6c) && (0 < local_68)) {
    iVar3 = (**(code **)(*param_1 + 0x17c))(param_1,param_2,DAT_00489608);
    if (iVar3 != 0) {
      iVar7 = (**(code **)(*param_1 + 400))(param_1,iVar3,DAT_0048960c);
      iVar8 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_00489610);
      if (iVar7 != iVar8) {
        FUN_00412800(param_1,param_2,DAT_0048961c);
        iVar7 = (**(code **)(*param_1 + 0x3c))(param_1);
        if (iVar7 != 0) {
          return;
        }
      }
    }
    iVar7 = (**(code **)(*param_1 + 0x17c))(param_1,param_2,DAT_00489604);
    if (iVar7 == 0) {
      _Java_NET_worlds_scape_Portal_setTransform_8(param_1,param_2);
      DAT_00489624 = DAT_00489624 + -1;
      return;
    }
    local_fc = 0;
    local_f8 = 0;
    if ((uVar4 & 1) != 0) {
      fVar13 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_3,DAT_0049fe14);
      local_fc = (int)ROUND((float)fVar13);
      fVar13 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_3,DAT_0049ff30);
      local_f8 = (int)ROUND((float)fVar13);
      iVar8 = local_fc - local_74;
      iVar11 = local_f8 - local_70;
      if ((uVar5 & 4) != 0) {
        iVar8 = local_6c - iVar8;
      }
      (**(code **)(*param_1 + 0x1bc))(param_1,param_3,DAT_0049fe14,(float)iVar8);
      (**(code **)(*param_1 + 0x1bc))(param_1,param_3,DAT_0049ff30,(float)iVar11);
    }
    FUN_00419260(iVar6,&local_64);
    FUN_00419200(iVar6,&local_58);
    FUN_00419230(iVar6,&local_4c);
    local_40 = local_64;
    local_3c = local_60;
    local_38 = local_5c;
    local_34 = local_58;
    local_30 = local_54;
    local_2c = local_50;
    local_28 = local_4c;
    local_24 = local_48;
    local_20 = local_44;
    uVar9 = FUN_00425380(param_1,iVar7);
    FUN_0041a080(&local_40,uVar9);
    FUN_0041a0b0(&local_34,uVar9);
    FUN_0041a0b0(&local_28,uVar9);
    FUN_00419c50(iVar6,local_40,local_3c,local_38);
    FUN_00419bf0(iVar6,local_34,local_30,local_2c);
    FUN_00419c20(iVar6,local_28,local_24,local_20);
    iVar7 = (**(code **)(*param_1 + 0x17c))(param_1,param_2,DAT_00489614);
    if (iVar7 == 0) {
      if (iVar3 == 0) {
        FUN_00402800(s_nPortal_00470780,0x295);
      }
      iVar7 = FUN_0041c530(param_1,iVar3,DAT_00489620);
      iVar3 = (**(code **)(*param_1 + 0x3c))(param_1);
      if (iVar3 != 0) {
        return;
      }
      (**(code **)(*param_1 + 0x1a0))(param_1,param_2,DAT_00489614,iVar7);
    }
    if (iVar7 == 0) {
      DAT_00489624 = DAT_00489624 + -1;
      (**(code **)(*param_1 + 0x1b4))(param_1,param_2,DAT_00489600,0xffffffff);
      iVar3 = FUN_00412cf0(param_1,param_2);
      if (iVar3 != 0) {
        iVar6 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_00489600);
        if ((iVar6 == 2) && (uVar4 = FUN_00412d20(param_1,param_2), (uVar4 & 0x40) == 0)) {
          FUN_00419d60(iVar3,0);
        }
        else {
          _Java_NET_worlds_scape_WObject_updateVisible_8(param_1,param_2);
        }
      }
      return;
    }
    FUN_004127e0(param_1,iVar7);
    iVar3 = FUN_00412cf0(param_1,iVar7);
    if (iVar3 == 0) {
      local_ec = 0;
    }
    else {
      local_ec = FUN_00419510(iVar3);
    }
    if (local_ec == 0) {
      DAT_00489624 = DAT_00489624 + -1;
      (**(code **)(*param_1 + 0x1b4))(param_1,param_2,DAT_00489600,0xffffffff);
      iVar3 = FUN_00412cf0(param_1,param_2);
      if (iVar3 != 0) {
        iVar6 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_00489600);
        if ((iVar6 == 2) && (uVar4 = FUN_00412d20(param_1,param_2), (uVar4 & 0x40) == 0)) {
          FUN_00419d60(iVar3,0);
        }
        else {
          _Java_NET_worlds_scape_WObject_updateVisible_8(param_1,param_2);
        }
      }
      return;
    }
    FUN_00419cb0(iVar6,local_94 + local_74,local_90 + local_70,local_6c,local_68);
    fVar1 = ((float)local_6c * local_84) / (float)local_8c;
    fVar2 = ((float)local_68 * local_80) / (float)local_88;
    FUN_00419d00(iVar6,fVar1,fVar2);
    bVar12 = (uVar5 & 4) != 0;
    fVar1 = (local_7c - ((float)(local_74 * 2) * local_84) / (float)local_8c) - (fVar1 - local_84);
    if (bVar12) {
      fVar1 = -fVar1;
    }
    FUN_00419c80(iVar6,fVar1,
                 (fVar2 - local_80) +
                 ((float)(local_70 * 2) * local_80) / (float)local_88 + local_78);
    FUN_00419260(iVar6,&local_1c);
    fVar13 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_2,DAT_004895f4);
    fVar14 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_2,DAT_004895f8);
    fVar15 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_2,DAT_004895fc);
    if (((float)fVar15 - local_14) * ((float)fVar15 - local_14) +
        ((float)fVar14 - local_18) * ((float)fVar14 - local_18) +
        ((float)fVar13 - local_1c) * ((float)fVar13 - local_1c) < (float)_DAT_004708b0) {
      pvVar10 = FUN_00453ed0();
      *(undefined4 *)((int)pvVar10 + 4) = 0x21;
    }
    FUN_00414aa0(param_1,local_ec,param_3,iVar6);
    if ((bVar12) && ((uVar4 & 2) != 0)) {
      FUN_00417f40(iVar6);
    }
    if (((uVar4 & 1) != 0) && (iVar3 = (**(code **)(*param_1 + 0x3c))(param_1), iVar3 == 0)) {
      (**(code **)(*param_1 + 0x1bc))(param_1,param_3,DAT_0049fe14,(float)local_fc);
      (**(code **)(*param_1 + 0x1bc))(param_1,param_3,DAT_0049ff30,(float)local_f8);
    }
    FUN_00419c50(iVar6,local_64,local_60,local_5c);
    FUN_00419bf0(iVar6,local_58,local_54,local_50);
    FUN_00419c20(iVar6,local_4c,local_48,local_44);
    FUN_00419cb0(iVar6,local_94,local_90,local_8c,local_88);
    FUN_00419d00(iVar6,local_84,local_80);
    FUN_00419c80(iVar6,local_7c,local_78);
    DAT_00489624 = DAT_00489624 + -1;
    return;
  }
  DAT_00489624 = DAT_00489624 + -1;
  return;
}


