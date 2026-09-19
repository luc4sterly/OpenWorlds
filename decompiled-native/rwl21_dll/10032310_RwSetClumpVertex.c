// 10032310 RwSetClumpVertex [Global]
// programa: RWL21.DLL

int RwSetClumpVertex(int param_1,int param_2,float *param_3)

{
  float *pfVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined3 extraout_var;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  bool bVar7;
  uint local_24;
  float fStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  float fStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  int iStack_4;
  
                    /* 0x32310  391  RwSetClumpVertex */
  if ((param_1 == 0) || (param_3 == (float *)0x0)) {
    FUN_1000cba0(1);
  }
  else if ((param_2 < -7) || (*(int *)(*(int *)(param_1 + 0x88) + 8) + -7 <= param_2)) {
    FUN_1000cba0(0x19);
  }
  else {
    pfVar1 = (float *)FUN_10041c90(*(int *)(param_1 + 0x88),param_2);
    local_24 = (uint)*(ushort *)(pfVar1 + 0x1b);
    puVar2 = (undefined4 *)(**(code **)(PTR_DAT_1005b69c + 0x34c))(local_24 * 4);
    if (puVar2 != (undefined4 *)0x0) {
      iVar3 = RwAddHintToClump(param_1,4);
      if (iVar3 == 0) {
        (**(code **)(PTR_DAT_1005b69c + 0x358))(puVar2);
        return 0;
      }
      *pfVar1 = *param_3;
      pfVar1[1] = param_3[1];
      pfVar1[2] = param_3[2];
      puVar5 = (undefined4 *)pfVar1[0x1c];
      puVar6 = puVar2;
      for (uVar4 = local_24; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar6 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
      for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
        *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
        puVar5 = (undefined4 *)((int)puVar5 + 1);
        puVar6 = (undefined4 *)((int)puVar6 + 1);
      }
      puVar5 = puVar2 + local_24;
      do {
        puVar5 = puVar5 + -1;
        bVar7 = local_24 == 0;
        local_24 = local_24 - 1;
        if (bVar7) {
          FUN_10041df0((int)pfVar1);
          FUN_10041ec0((int)pfVar1);
          FUN_100421e0(*(int *)(param_1 + 0x88),pfVar1);
          *(undefined4 *)(param_1 + 0xc0) = 0;
          *(undefined4 *)(param_1 + 200) = 0;
          *(undefined4 *)(param_1 + 0xc4) = 0;
          (**(code **)(PTR_DAT_1005b69c + 0x358))(puVar2);
          return param_1;
        }
        puVar6 = (undefined4 *)*puVar5;
        iStack_4 = FUN_100321a0((int)puVar6);
        FUN_10001100((int)puVar6,&fStack_1c,&fStack_10);
        puVar6[7] = fStack_1c;
        puVar6[8] = uStack_18;
        puVar6[9] = uStack_14;
        puVar6[4] = fStack_10;
        puVar6[5] = uStack_c;
        puVar6[6] = uStack_8;
        for (iVar3 = puVar6[0xc]; iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x30)) {
          FUN_10001100(iVar3,&fStack_1c,&fStack_10);
          *(float *)(iVar3 + 0x1c) = fStack_1c;
          *(undefined4 *)(iVar3 + 0x20) = uStack_18;
          *(undefined4 *)(iVar3 + 0x24) = uStack_14;
          *(float *)(iVar3 + 0x10) = fStack_10;
          *(undefined4 *)(iVar3 + 0x14) = uStack_c;
          *(undefined4 *)(iVar3 + 0x18) = uStack_8;
        }
      } while ((iStack_4 == 0) ||
              (bVar7 = FUN_100320d0(param_1,puVar6), CONCAT31(extraout_var,bVar7) != 0));
      return 0;
    }
    FUN_1000cba0(3);
  }
  return 0;
}


