// 0041b170 _Java_NET_worlds_scape_Portal_setTransform@8 [Global]
// programa: gamma.dll

void _Java_NET_worlds_scape_Portal_setTransform_8(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  float10 fVar5;
  float10 fVar6;
  float10 fVar7;
  float local_5c;
  float local_58;
  float local_54;
  float local_50 [4];
  float local_40;
  float local_30;
  float local_20;
  float local_14;
  
                    /* 0x1b170  265  _Java_NET_worlds_scape_Portal_setTransform@8 */
  iVar1 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_00489600);
  iVar2 = FUN_00412cf0(param_1,param_2);
  if ((iVar2 != 0) && (iVar1 == 2)) {
    if (iVar2 == 0) {
      FUN_00402800(s_nPortal_00470780,0xa8);
    }
    iVar1 = (**(code **)(*param_1 + 0x17c))(param_1,param_2,DAT_00489604);
    if (iVar1 == 0) {
      iVar1 = FUN_00425250(param_1);
      (**(code **)(*param_1 + 0x1a0))(param_1,param_2,DAT_00489604,iVar1);
    }
    if (iVar1 == 0) {
      FUN_00402800(s_nPortal_00470780,0xaf);
    }
    iVar1 = FUN_00425380(param_1,iVar1);
    if (iVar1 == 0) {
      FUN_00402800(s_nPortal_00470780,0xb2);
    }
    FUN_00425280(param_1,param_2,&local_5c);
    uVar3 = FUN_00419950();
    FUN_004193c0(iVar2,uVar3);
    FUN_00418b10(uVar3,DAT_004708a8 / local_5c,DAT_004708a8 / local_58,DAT_004708a8 / local_54);
    FUN_00419860(uVar3,iVar1);
    FUN_004198f0();
    uVar4 = FUN_00412d20(param_1,param_2);
    if ((uVar4 & 4) != 0) {
      FUN_00419740(iVar1,local_50);
      local_50[0] = -local_50[0];
      local_40 = -local_40;
      local_30 = -local_30;
      local_20 = -local_20;
      if ((byte)((byte)((ushort)((ushort)(NAN(DAT_004708a8) || NAN(local_14)) << 10) >> 8) |
                (byte)((ushort)((ushort)(DAT_004708a8 == local_14) << 0xe) >> 8)) != 0x40) {
        local_14 = 1.0;
      }
      FUN_00419f90(iVar1,local_50);
    }
    fVar5 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_2,DAT_004895f0);
    FUN_00418ad0(iVar1,(float)fVar5,DAT_004708ac,DAT_004708ac,DAT_004708a8);
    fVar5 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_2,DAT_004895f4);
    fVar6 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_2,DAT_004895f8);
    fVar7 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_2,DAT_004895fc);
    FUN_00418d60(iVar1,(float)fVar5,(float)fVar6,(float)fVar7);
    return;
  }
  (**(code **)(*param_1 + 0x1a0))(param_1,param_2,DAT_00489604,0);
  return;
}


