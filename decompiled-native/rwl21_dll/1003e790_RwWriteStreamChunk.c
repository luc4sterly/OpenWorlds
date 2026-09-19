// 1003e790 RwWriteStreamChunk [Global]
// programa: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool RwWriteStreamChunk(int *param_1,int param_2,uint *param_3,float param_4)

{
  int iVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  uint *puVar6;
  undefined3 extraout_var_05;
  undefined3 extraout_var_06;
  undefined3 extraout_var_07;
  undefined3 extraout_var_08;
  undefined3 extraout_var_09;
  undefined3 extraout_var_10;
  int *piVar7;
  undefined3 extraout_var_11;
  undefined3 extraout_var_12;
  undefined3 extraout_var_13;
  undefined3 extraout_var_14;
  undefined3 extraout_var_15;
  undefined3 extraout_var_16;
  undefined3 extraout_var_17;
  undefined3 extraout_var_18;
  undefined3 extraout_var_19;
  undefined3 extraout_var_20;
  undefined3 extraout_var_21;
  undefined3 extraout_var_22;
  undefined3 extraout_var_23;
  undefined3 extraout_var_24;
  undefined3 extraout_var_25;
  undefined3 extraout_var_26;
  undefined3 extraout_var_27;
  undefined3 extraout_var_28;
  undefined3 extraout_var_29;
  undefined4 *puVar8;
  undefined3 extraout_var_30;
  undefined3 extraout_var_31;
  undefined3 extraout_var_32;
  undefined3 extraout_var_33;
  undefined3 extraout_var_34;
  undefined3 extraout_var_35;
  undefined3 extraout_var_36;
  undefined3 extraout_var_37;
  undefined3 extraout_var_38;
  undefined3 extraout_var_39;
  undefined3 extraout_var_40;
  undefined3 extraout_var_41;
  undefined3 extraout_var_42;
  undefined3 extraout_var_43;
  undefined3 extraout_var_44;
  undefined3 extraout_var_45;
  undefined3 extraout_var_46;
  undefined3 extraout_var_47;
  undefined3 extraout_var_48;
  undefined3 extraout_var_49;
  undefined3 extraout_var_50;
  undefined3 extraout_var_51;
  float *pfVar9;
  undefined3 extraout_var_52;
  undefined3 extraout_var_53;
  undefined3 extraout_var_54;
  undefined3 extraout_var_55;
  undefined3 extraout_var_56;
  undefined3 extraout_var_57;
  undefined3 extraout_var_58;
  undefined3 extraout_var_59;
  undefined3 extraout_var_60;
  undefined3 extraout_var_61;
  undefined3 extraout_var_62;
  undefined3 extraout_var_63;
  undefined3 extraout_var_64;
  undefined3 extraout_var_65;
  undefined3 extraout_var_66;
  undefined3 extraout_var_67;
  undefined3 extraout_var_68;
  undefined3 extraout_var_69;
  undefined3 extraout_var_70;
  undefined3 extraout_var_71;
  undefined3 extraout_var_72;
  undefined3 extraout_var_73;
  undefined3 extraout_var_74;
  uint uVar10;
  int *piVar11;
  float *pfVar12;
  uint uVar13;
  undefined4 *puVar14;
  int *piVar15;
  undefined4 *puVar16;
  float10 fVar17;
  float fVar18;
  float local_888;
  uint uStack_884;
  float local_880;
  uint local_87c;
  uint local_878;
  float local_874 [4];
  uint local_864;
  uint local_860;
  float local_85c;
  float local_858;
  float local_854;
  float local_850;
  uint local_84c;
  uint local_848;
  float local_844;
  uint local_840;
  float local_83c;
  float local_838;
  float local_82c;
  float local_828;
  float local_824 [3];
  uint local_818;
  float *local_814;
  float *pfStack_810;
  uint local_80c;
  uint uStack_808;
  int iStack_804;
  undefined4 local_800;
  uint local_7fc;
  float local_7f8;
  float local_7f4;
  float local_7f0;
  float local_7ec;
  undefined4 local_400;
  uint local_3fc;
  
                    /* 0x3e790  528  RwWriteStreamChunk */
  if (param_2 < 0x43414d46) {
    if (param_2 == 0x43414d45) {
      if (param_3 == (uint *)0x0) {
        FUN_1000cba0(1);
        return false;
      }
      iVar4 = RwGetChunkSize(0x43414d45,(int *)param_3,(uint)param_4);
      uVar5 = iVar4 - 8;
      local_400 = 0x454d4143;
      local_3fc = (uVar5 & 0xff00 | uVar5 * 0x10000) << 8 | (uVar5 & 0xff0000 | uVar5 >> 0x10) >> 8;
      bVar2 = RwWriteStream(param_1,&local_400,8);
      if (CONCAT31(extraout_var_06,bVar2) == 0) {
        return false;
      }
      local_880 = (float)((uint)param_4 & 8);
      if ((local_880 == 0.0) || (param_3[0x28] == 0)) {
        local_840 = 0;
      }
      else {
        local_840 = 1;
      }
      local_848 = *(undefined4 *)(param_3[0x40] + 0x1c);
      local_844 = *(float *)(param_3[0x40] + 0x20);
      local_874[0] = (float)RwGetCameraProjection((int)param_3);
      RwGetCameraBackColor((int)param_3,local_824);
      fVar17 = RwGetCameraNearClipping((int)param_3);
      local_83c = (float)fVar17;
      fVar17 = RwGetCameraFarClipping((int)param_3);
      local_838 = (float)fVar17;
      RwGetCameraBackdropOffset((int)param_3,local_874 + 1,local_874 + 2);
      RwGetCameraBackdropViewportRect((int)param_3,local_874 + 3,&local_864,&local_860,&local_85c);
      RwGetCameraViewport((int)param_3,&local_858,&local_854,&local_850,&local_84c);
      RwGetCameraViewwindow((int)param_3,&local_82c,&local_828);
      local_400 = 0x17;
      pfVar9 = local_874;
      do {
        fVar18 = *pfVar9;
        *pfVar9 = (float)(((uint)fVar18 & 0xff00 | (int)fVar18 << 0x10) << 8 |
                         ((uint)fVar18 & 0xff0000 | (uint)fVar18 >> 0x10) >> 8);
        local_400 = local_400 + -1;
        pfVar9 = pfVar9 + 1;
      } while (local_400 != 0);
      bVar2 = RwWriteStreamChunk(param_1,0x53545254,(uint *)local_874,1.28919e-43);
      if (CONCAT31(extraout_var_07,bVar2) == 0) {
        return false;
      }
      fVar18 = 0.0;
      puVar6 = (uint *)FUN_10009dc0((int)param_3);
      bVar2 = RwWriteStreamChunk(param_1,0x4d415458,puVar6,fVar18);
      if (CONCAT31(extraout_var_08,bVar2) == 0) {
        return false;
      }
      RwGetCameraViewOffset((int)param_3,&local_800);
      bVar2 = RwWriteStreamChunk(param_1,0x56334420,&local_800,0.0);
      if (CONCAT31(extraout_var_09,bVar2) != 0) {
        if (local_880 == 0.0) {
          return true;
        }
        if ((uint *)param_3[0x28] == (uint *)0x0) {
          return true;
        }
        bVar2 = RwWriteStreamChunk(param_1,0x52415354,(uint *)param_3[0x28],param_4);
        if (CONCAT31(extraout_var_10,bVar2) != 0) {
          return true;
        }
        return false;
      }
      return false;
    }
    if (param_2 == 0x41544f4d) {
      iVar4 = RwGetChunkSize(0x41544f4d,(int *)param_3,(uint)param_4);
      uVar5 = iVar4 - 8;
      local_800 = 2.1740034e+08;
      local_7fc = (uVar5 & 0xff00 | uVar5 * 0x10000) << 8 | (uVar5 & 0xff0000 | uVar5 >> 0x10) >> 8;
      bVar2 = RwWriteStream(param_1,&local_800,8);
      if (CONCAT31(extraout_var,bVar2) == 0) {
        return false;
      }
      local_874[0] = (float)param_3[0x23];
      local_874[1] = (float)param_3[0x24];
      if (((uint)param_4 & 0x10) == 0) {
        local_874[2] = 0.0;
      }
      else {
        local_874[2] = (float)param_3[0x3a];
      }
      local_854 = (float)param_3[0x62];
      local_850 = (float)param_3[99];
      local_84c = param_3[100];
      local_848 = RwGetClumpNumChildren((int)param_3);
      fVar17 = RwGetClumpLightSampleRate((int)param_3);
      local_844 = (float)fVar17;
      local_800 = 1.82169e-44;
      pfVar9 = local_874;
      do {
        fVar18 = *pfVar9;
        *pfVar9 = (float)(((uint)fVar18 & 0xff00 | (int)fVar18 << 0x10) << 8 |
                         ((uint)fVar18 & 0xff0000 | (uint)fVar18 >> 0x10) >> 8);
        local_800 = (float)((int)local_800 - 1);
        pfVar9 = pfVar9 + 1;
      } while (local_800 != 0.0);
      bVar2 = RwWriteStreamChunk(param_1,0x53545254,(uint *)local_874,7.28675e-44);
      if (CONCAT31(extraout_var_00,bVar2) == 0) {
        return false;
      }
      bVar2 = RwWriteStreamChunk(param_1,0x4d415458,param_3 + 0x3b,0.0);
      if (CONCAT31(extraout_var_01,bVar2) == 0) {
        return false;
      }
      bVar2 = RwWriteStreamChunk(param_1,0x4d415458,param_3 + 0x4c,0.0);
      if (CONCAT31(extraout_var_02,bVar2) != 0) {
        bVar2 = RwWriteStreamChunk(param_1,0x564c5354,param_3,param_4);
        if (CONCAT31(extraout_var_03,bVar2) == 0) {
          return false;
        }
        bVar2 = RwWriteStreamChunk(param_1,0x504c5354,param_3,param_4);
        if (CONCAT31(extraout_var_04,bVar2) != 0) {
          puVar6 = (uint *)RwGetFirstChildClump((int)param_3);
          while( true ) {
            if (puVar6 == (uint *)0x0) {
              return true;
            }
            bVar2 = RwWriteStreamChunk(param_1,0x41544f4d,puVar6,param_4);
            if (CONCAT31(extraout_var_05,bVar2) == 0) break;
            puVar6 = (uint *)RwGetNextClump((int)puVar6);
          }
          return false;
        }
        return false;
      }
      return false;
    }
  }
  else {
    if (0x44415441 < param_2) {
      if (param_2 < 0x4d414c55) {
        if (param_2 != 0x4d414c54) {
          if (param_2 == 0x4c495445) {
            if (param_3 == (uint *)0x0) {
              FUN_1000cba0(1);
              return false;
            }
            iVar4 = RwGetChunkSize(0x4c495445,(int *)param_3,(uint)param_4);
            uVar5 = iVar4 - 8;
            local_800 = 3396.581;
            local_7fc = (uVar5 & 0xff00 | uVar5 * 0x10000) << 8 |
                        (uVar5 & 0xff0000 | uVar5 >> 0x10) >> 8;
            bVar2 = RwWriteStream(param_1,&local_800,8);
            if (CONCAT31(extraout_var_18,bVar2) != 0) {
              local_874[0] = (float)param_3[1];
              local_874[1] = (float)param_3[0x21];
              local_874[2] = (float)param_3[0x19];
              local_874[3] = (float)param_3[0x1a];
              local_864 = param_3[0x1b];
              local_860 = param_3[0x1c];
              local_85c = (float)param_3[0x1d];
              local_854 = (float)param_3[0x1e];
              local_850 = (float)param_3[0x1f];
              local_84c = param_3[0x20];
              local_848 = param_3[0x16];
              local_844 = (float)param_3[0x17];
              local_840 = param_3[0x18];
              iVar4 = 0xe;
              pfVar9 = local_874;
              do {
                fVar18 = *pfVar9;
                iVar4 = iVar4 + -1;
                *pfVar9 = (float)(((uint)fVar18 & 0xff00 | (int)fVar18 << 0x10) << 8 |
                                 ((uint)fVar18 & 0xff0000 | (uint)fVar18 >> 0x10) >> 8);
                pfVar9 = pfVar9 + 1;
              } while (iVar4 != 0);
              bVar2 = RwWriteStreamChunk(param_1,0x53545254,(uint *)local_874,7.84727e-44);
              if (CONCAT31(extraout_var_19,bVar2) != 0) {
                bVar2 = RwWriteStreamChunk(param_1,0x4d415458,param_3 + 2,0.0);
                return (bool)('\x01' - (CONCAT31(extraout_var_20,bVar2) == 0));
              }
              return false;
            }
            return false;
          }
          goto LAB_1003e8c4;
        }
        local_888 = *(float *)(DAT_1005b798[2] + 8);
        iVar4 = RwGetChunkSize(0x4d414c54,(int *)param_3,(uint)param_4);
        uVar5 = iVar4 - 8;
        local_800 = 3.5090756e+12;
        local_7fc = (uVar5 & 0xff00 | uVar5 * 0x10000) << 8 |
                    (uVar5 & 0xff0000 | uVar5 >> 0x10) >> 8;
        bVar2 = RwWriteStream(param_1,&local_800,8);
        if (CONCAT31(extraout_var_21,bVar2) == 0) {
          return false;
        }
        iVar4 = 3;
        local_874[0] = local_888;
        local_874[1] = 5.60519e-44;
        local_874[2] = param_4;
        pfVar9 = local_874;
        do {
          fVar18 = *pfVar9;
          iVar4 = iVar4 + -1;
          *pfVar9 = (float)(((uint)fVar18 & 0xff00 | (int)fVar18 << 0x10) << 8 |
                           ((uint)fVar18 & 0xff0000 | (uint)fVar18 >> 0x10) >> 8);
          pfVar9 = pfVar9 + 1;
        } while (iVar4 != 0);
        bVar2 = RwWriteStreamChunk(param_1,0x53545254,(uint *)local_874,1.68156e-44);
        if (CONCAT31(extraout_var_22,bVar2) == 0) {
          return false;
        }
        uVar5 = 1;
        if (0 < (int)local_888) {
          do {
            if (((uint)((int *)DAT_1005b798[2])[2] < uVar5) || (uVar5 == 0)) {
              puVar16 = (undefined4 *)0x0;
            }
            else {
              puVar16 = *(undefined4 **)(*(int *)DAT_1005b798[2] + -4 + uVar5 * 4);
            }
            local_874[1] = (float)*puVar16;
            local_874[2] = (float)(uint)*(byte *)(puVar16 + 0xc);
            RwGetMaterialColor((int)puVar16,local_874 + 3);
            fVar17 = RwGetMaterialOpacity((int)puVar16);
            local_85c = (float)fVar17;
            fVar17 = RwGetMaterialAmbient((int)puVar16);
            local_858 = (float)fVar17;
            fVar17 = RwGetMaterialDiffuse((int)puVar16);
            local_854 = (float)fVar17;
            fVar17 = RwGetMaterialSpecular((int)puVar16);
            local_850 = (float)fVar17;
            iVar4 = RwGetMaterialTexture((int)puVar16);
            if (iVar4 == 0) {
              local_874[0] = 0.0;
            }
            else {
              piVar7 = *(int **)DAT_1005b798[1];
              uVar13 = 0;
              uVar10 = ((undefined4 *)DAT_1005b798[1])[2];
              if (uVar10 != 0) {
                do {
                  if (*piVar7 == iVar4) {
                    local_874[0] = (float)(uVar13 + 1);
                    break;
                  }
                  piVar7 = piVar7 + 1;
                  uVar13 = uVar13 + 1;
                } while (uVar13 < uVar10);
              }
            }
            iVar4 = 10;
            pfVar9 = local_874;
            do {
              fVar18 = *pfVar9;
              iVar4 = iVar4 + -1;
              *pfVar9 = (float)(((uint)fVar18 & 0xff00 | (int)fVar18 << 0x10) << 8 |
                               ((uint)fVar18 & 0xff0000 | (uint)fVar18 >> 0x10) >> 8);
              pfVar9 = pfVar9 + 1;
            } while (iVar4 != 0);
            bVar2 = RwWriteStream(param_1,local_874,0x28);
            if (CONCAT31(extraout_var_23,bVar2) == 0) {
              return false;
            }
            uVar5 = uVar5 + 1;
          } while ((int)uVar5 <= (int)local_888);
        }
      }
      else if (param_2 < 0x4d415459) {
        if (param_2 == 0x4d415458) {
          if (param_3 == (uint *)0x0) {
            FUN_1000cba0(1);
            return false;
          }
          iVar4 = RwGetChunkSize(0x4d415458,(int *)param_3,(uint)param_4);
          uVar5 = iVar4 - 8;
          local_800 = 9.335077e+14;
          local_7fc = (uVar5 & 0xff00 | uVar5 * 0x10000) << 8 |
                      (uVar5 & 0xff0000 | uVar5 >> 0x10) >> 8;
          bVar2 = RwWriteStream(param_1,&local_800,8);
          if (CONCAT31(extraout_var_27,bVar2) != 0) {
            RwGetMatrixElements(param_3,local_874);
            iVar4 = 0x10;
            pfVar9 = local_874;
            do {
              fVar18 = *pfVar9;
              iVar4 = iVar4 + -1;
              *pfVar9 = (float)(((uint)fVar18 & 0xff00 | (int)fVar18 << 0x10) << 8 |
                               ((uint)fVar18 & 0xff0000 | (uint)fVar18 >> 0x10) >> 8);
              pfVar9 = pfVar9 + 1;
            } while (iVar4 != 0);
            bVar2 = RwWriteStreamChunk(param_1,0x53545254,(uint *)local_874,8.96831e-44);
            return (bool)('\x01' - (CONCAT31(extraout_var_28,bVar2) == 0));
          }
          return false;
        }
        if (param_2 != 0x4d415452) goto LAB_1003e8c4;
        if (param_3 == (uint *)0x0) {
          FUN_1000cba0(1);
          return false;
        }
        iVar4 = RwGetChunkSize(0x4d415452,(int *)param_3,(uint)param_4);
        uVar5 = iVar4 - 8;
        local_800 = 2.2790716e+11;
        local_7fc = (uVar5 & 0xff00 | uVar5 * 0x10000) << 8 |
                    (uVar5 & 0xff0000 | uVar5 >> 0x10) >> 8;
        bVar2 = RwWriteStream(param_1,&local_800,8);
        if (CONCAT31(extraout_var_24,bVar2) == 0) {
          return false;
        }
        iVar4 = RwGetMaterialTexture((int)param_3);
        local_874[0] = (float)(uint)(iVar4 != 0);
        local_874[1] = (float)*param_3;
        local_874[2] = (float)(uint)(byte)param_3[0xc];
        RwGetMaterialColor((int)param_3,local_874 + 3);
        fVar17 = RwGetMaterialOpacity((int)param_3);
        local_85c = (float)fVar17;
        fVar17 = RwGetMaterialAmbient((int)param_3);
        local_858 = (float)fVar17;
        fVar17 = RwGetMaterialDiffuse((int)param_3);
        local_854 = (float)fVar17;
        fVar17 = RwGetMaterialSpecular((int)param_3);
        local_850 = (float)fVar17;
        local_800 = 1.4013e-44;
        pfVar9 = local_874;
        do {
          fVar18 = *pfVar9;
          *pfVar9 = (float)(((uint)fVar18 & 0xff00 | (int)fVar18 << 0x10) << 8 |
                           ((uint)fVar18 & 0xff0000 | (uint)fVar18 >> 0x10) >> 8);
          local_800 = (float)((int)local_800 - 1);
          pfVar9 = pfVar9 + 1;
        } while (local_800 != 0.0);
        bVar2 = RwWriteStreamChunk(param_1,0x53545254,(uint *)local_874,5.60519e-44);
        if (CONCAT31(extraout_var_25,bVar2) == 0) {
          return false;
        }
        iVar4 = RwGetMaterialTexture((int)param_3);
        if (iVar4 != 0) {
          puVar6 = (uint *)RwGetMaterialTexture((int)param_3);
          bVar2 = RwWriteStreamChunk(param_1,0x54455855,puVar6,param_4);
          if (CONCAT31(extraout_var_26,bVar2) == 0) {
            return false;
          }
        }
      }
      else if (param_2 < 0x504c5355) {
        if (param_2 != 0x504c5354) {
          if (param_2 == 0x50414c4c) {
            iVar4 = RwGetChunkSize(0x50414c4c,(int *)param_3,(uint)param_4);
            uVar5 = iVar4 - 8;
            local_880 = 53544256.0;
            local_87c = (uVar5 & 0xff00 | uVar5 * 0x10000) << 8 |
                        (uVar5 & 0xff0000 | uVar5 >> 0x10) >> 8;
            bVar2 = RwWriteStream(param_1,&local_880,8);
            if (CONCAT31(extraout_var_29,bVar2) != 0) {
              RwGetPaletteEntries(0,0x100,(int)&local_400);
              puVar16 = &local_400;
              puVar14 = &local_800;
              do {
                puVar8 = puVar16 + 1;
                *(undefined1 *)puVar14 = *(undefined1 *)puVar16;
                *(undefined1 *)((int)puVar14 + 1) = *(undefined1 *)((int)puVar16 + 1);
                *(undefined1 *)((int)puVar14 + 2) = *(undefined1 *)((int)puVar16 + 2);
                *(undefined1 *)((int)puVar14 + 3) = 0;
                puVar16 = puVar8;
                puVar14 = puVar14 + 1;
              } while (puVar8 < &stack0x00000000);
              bVar2 = RwWriteStream(param_1,&local_800,0x400);
              return (bool)('\x01' - (CONCAT31(extraout_var_30,bVar2) == 0));
            }
            return false;
          }
          goto LAB_1003e8c4;
        }
        local_400 = param_3[0x22];
        local_814 = (float *)param_3[0x26];
        iVar4 = RwGetChunkSize(0x504c5354,(int *)param_3,(uint)param_4);
        uVar5 = iVar4 - 8;
        local_800 = 3.6300736e+12;
        local_7fc = (uVar5 & 0xff00 | uVar5 * 0x10000) << 8 |
                    (uVar5 & 0xff0000 | uVar5 >> 0x10) >> 8;
        bVar2 = RwWriteStream(param_1,&local_800,8);
        if (CONCAT31(extraout_var_31,bVar2) == 0) {
          return false;
        }
        local_874[0] = *local_814;
        local_878 = (uint)param_4 & 4;
        local_80c = (uint)param_4 & 0x10;
        local_818 = (uint)param_4 & 1;
        iVar4 = 3;
        local_874[1] = (float)(((((uint)param_4 & 0x10) == 0) - 1 & 4) +
                               ((((uint)param_4 & 4) == 0) - 1 & 0xc) +
                               ((((uint)param_4 & 1) == 0) - 1 & 0xc) + 8);
        local_874[2] = param_4;
        pfVar9 = local_874;
        do {
          fVar18 = *pfVar9;
          iVar4 = iVar4 + -1;
          *pfVar9 = (float)(((uint)fVar18 & 0xff00 | (int)fVar18 << 0x10) << 8 |
                           ((uint)fVar18 & 0xff0000 | (uint)fVar18 >> 0x10) >> 8);
          pfVar9 = pfVar9 + 1;
        } while (iVar4 != 0);
        bVar2 = RwWriteStreamChunk(param_1,0x53545254,(uint *)local_874,1.68156e-44);
        if (CONCAT31(extraout_var_32,bVar2) == 0) {
          return false;
        }
        uStack_884 = 0;
        if (0 < (int)*local_814) {
          pfStack_810 = local_814 + 2;
          do {
            piVar7 = (int *)*pfStack_810;
            if (*piVar7 == 0) {
              local_874[0] = 0.0;
            }
            else {
              piVar11 = *(int **)DAT_1005b798[2];
              uVar10 = 0;
              uVar5 = ((undefined4 *)DAT_1005b798[2])[2];
              if (uVar5 != 0) {
                do {
                  if (*piVar11 == *piVar7) {
                    local_874[0] = (float)(uVar10 + 1);
                    break;
                  }
                  piVar11 = piVar11 + 1;
                  uVar10 = uVar10 + 1;
                } while (uVar10 < uVar5);
              }
            }
            iVar4 = 2;
            local_874[1] = (float)(uint)*(byte *)((int)piVar7 + 0x3a);
            pfVar9 = local_874;
            do {
              fVar18 = *pfVar9;
              iVar4 = iVar4 + -1;
              *pfVar9 = (float)(((uint)fVar18 & 0xff00 | (int)fVar18 << 0x10) << 8 |
                               ((uint)fVar18 & 0xff0000 | (uint)fVar18 >> 0x10) >> 8);
              pfVar9 = pfVar9 + 1;
            } while (iVar4 != 0);
            bVar2 = RwWriteStream(param_1,local_874,8);
            if (CONCAT31(extraout_var_33,bVar2) == 0) {
              return false;
            }
            iVar4 = 0;
            if (*(char *)((int)piVar7 + 0x3a) != '\0') {
              piVar11 = piVar7 + 0xf;
              local_800 = (float)(local_400 + 0xc);
              piVar15 = &DAT_1005e070;
              do {
                iVar1 = *piVar11;
                piVar11 = piVar11 + 1;
                local_880 = 1.62551e-43;
                iVar4 = iVar4 + 1;
                *piVar15 = (uint)(iVar1 - (int)local_800) / 0x74 - 7;
                piVar15 = piVar15 + 1;
              } while (iVar4 < (int)(uint)*(byte *)((int)piVar7 + 0x3a));
            }
            uVar5 = (uint)*(byte *)((int)piVar7 + 0x3a);
            puVar6 = &DAT_1005e070;
            if (*(byte *)((int)piVar7 + 0x3a) != 0) {
              do {
                uVar10 = *puVar6;
                uVar5 = uVar5 - 1;
                *puVar6 = (uVar10 & 0xff00 | uVar10 << 0x10) << 8 |
                          (uVar10 & 0xff0000 | uVar10 >> 0x10) >> 8;
                puVar6 = puVar6 + 1;
              } while (uVar5 != 0);
            }
            bVar2 = RwWriteStream(param_1,&DAT_1005e070,(uint)*(byte *)((int)piVar7 + 0x3a) << 2);
            if (CONCAT31(extraout_var_34,bVar2) == 0) {
              return false;
            }
            if (local_818 != 0) {
              local_874[0] = (float)piVar7[4];
              iVar4 = 3;
              local_874[1] = (float)piVar7[5];
              local_874[2] = (float)piVar7[6];
              pfVar9 = local_874;
              do {
                fVar18 = *pfVar9;
                iVar4 = iVar4 + -1;
                *pfVar9 = (float)(((uint)fVar18 & 0xff00 | (int)fVar18 << 0x10) << 8 |
                                 ((uint)fVar18 & 0xff0000 | (uint)fVar18 >> 0x10) >> 8);
                pfVar9 = pfVar9 + 1;
              } while (iVar4 != 0);
              bVar2 = RwWriteStream(param_1,local_874,0xc);
              if (CONCAT31(extraout_var_35,bVar2) == 0) {
                return false;
              }
            }
            if (local_878 != 0) {
              local_874[0] = (float)piVar7[1] * (float)_DAT_100522a8;
              iVar4 = 3;
              local_874[1] = (float)piVar7[2] * (float)_DAT_100522a8;
              local_800 = (float)piVar7[3];
              local_874[2] = (float)piVar7[3] * (float)_DAT_100522a8;
              pfVar9 = local_874;
              do {
                fVar18 = *pfVar9;
                iVar4 = iVar4 + -1;
                *pfVar9 = (float)(((uint)fVar18 & 0xff00 | (int)fVar18 << 0x10) << 8 |
                                 ((uint)fVar18 & 0xff0000 | (uint)fVar18 >> 0x10) >> 8);
                pfVar9 = pfVar9 + 1;
              } while (iVar4 != 0);
              bVar2 = RwWriteStream(param_1,local_874,0xc);
              if (CONCAT31(extraout_var_36,bVar2) == 0) {
                return false;
              }
            }
            if (local_80c != 0) {
              iVar4 = 1;
              local_874[0] = (float)(int)(short)piVar7[0xe];
              pfVar9 = local_874;
              do {
                fVar18 = *pfVar9;
                iVar4 = iVar4 + -1;
                *pfVar9 = (float)(((uint)fVar18 & 0xff00 | (int)fVar18 << 0x10) << 8 |
                                 ((uint)fVar18 & 0xff0000 | (uint)fVar18 >> 0x10) >> 8);
                pfVar9 = pfVar9 + 1;
              } while (iVar4 != 0);
              bVar2 = RwWriteStream(param_1,local_874,4);
              if (CONCAT31(extraout_var_37,bVar2) == 0) {
                return false;
              }
            }
            uStack_884 = uStack_884 + 1;
            pfStack_810 = pfStack_810 + 1;
          } while ((int)uStack_884 < (int)*local_814);
        }
      }
      else if (param_2 < 0x52415355) {
        if (param_2 == 0x52415354) {
          if (param_3 == (uint *)0x0) {
            FUN_1000cba0(1);
            return false;
          }
          iVar4 = RwGetChunkSize(0x52415354,(int *)param_3,(uint)param_4);
          uVar5 = iVar4 - 8;
          local_400 = 0x54534152;
          local_3fc = (uVar5 * 0x10000 | uVar5 & 0xff00) << 8 |
                      (uVar5 >> 0x10 | uVar5 & 0xff0000) >> 8;
          bVar2 = RwWriteStream(param_1,&local_400,8);
          if (CONCAT31(extraout_var_41,bVar2) == 0) {
            return false;
          }
          local_874[0] = (float)RwGetRasterWidth((int)param_3);
          local_874[1] = (float)RwGetRasterHeight((int)param_3);
          local_874[2] = (float)RwGetRasterDepth((int)param_3);
          local_874[3] = (float)RwGetRasterStride((int)param_3);
          RwGetRasterInfo(param_3,&local_800);
          local_864 = (uint)local_800;
          local_860 = local_7fc;
          local_85c = local_7f8;
          local_858 = local_7f4;
          local_854 = local_7f0;
          iVar4 = 10;
          local_850 = local_7ec;
          pfVar9 = local_874;
          do {
            fVar18 = *pfVar9;
            iVar4 = iVar4 + -1;
            *pfVar9 = (float)(((uint)fVar18 & 0xff00 | (int)fVar18 << 0x10) << 8 |
                             ((uint)fVar18 & 0xff0000 | (uint)fVar18 >> 0x10) >> 8);
            pfVar9 = pfVar9 + 1;
          } while (iVar4 != 0);
          bVar2 = RwWriteStreamChunk(param_1,0x53545254,(uint *)local_874,5.60519e-44);
          if (CONCAT31(extraout_var_42,bVar2) == 0) {
            return false;
          }
          uStack_808 = RwGetRasterPixels((int)param_3);
          iVar4 = RwGetRasterStride((int)param_3);
          iStack_804 = RwGetRasterHeight((int)param_3);
          iStack_804 = iVar4 * iStack_804;
          bVar2 = RwWriteStreamChunk(param_1,0x44415441,&uStack_808,0.0);
          if (CONCAT31(extraout_var_43,bVar2) == 0) {
            RwReleaseRasterPixels((int)param_3);
            return false;
          }
          RwReleaseRasterPixels((int)param_3);
        }
        else {
          if (param_2 != 0x52414c54) goto LAB_1003e8c4;
          iVar4 = RwGetChunkSize(0x52414c54,(int *)param_3,(uint)param_4);
          uVar5 = iVar4 - 8;
          local_800 = 3.509077e+12;
          local_7fc = (uVar5 & 0xff00 | uVar5 * 0x10000) << 8 |
                      (uVar5 & 0xff0000 | uVar5 >> 0x10) >> 8;
          bVar2 = RwWriteStream(param_1,&local_800,8);
          if (CONCAT31(extraout_var_38,bVar2) == 0) {
            return false;
          }
          if (((uint)param_4 & 8) == 0) {
            local_888 = 0.0;
          }
          else {
            local_888 = *(float *)(*DAT_1005b798 + 8);
          }
          iVar4 = 3;
          local_874[0] = local_888;
          local_874[1] = 0.0;
          local_874[2] = param_4;
          pfVar9 = local_874;
          do {
            fVar18 = *pfVar9;
            iVar4 = iVar4 + -1;
            *pfVar9 = (float)(((uint)fVar18 & 0xff00 | (int)fVar18 << 0x10) << 8 |
                             ((uint)fVar18 & 0xff0000 | (uint)fVar18 >> 0x10) >> 8);
            pfVar9 = pfVar9 + 1;
          } while (iVar4 != 0);
          bVar2 = RwWriteStreamChunk(param_1,0x53545254,(uint *)local_874,1.68156e-44);
          if (CONCAT31(extraout_var_39,bVar2) == 0) {
            return false;
          }
          uVar5 = 1;
          if (0 < (int)local_888) {
            do {
              if (((uint)((int *)*DAT_1005b798)[2] < uVar5) || (uVar5 == 0)) {
                puVar6 = (uint *)0x0;
              }
              else {
                puVar6 = *(uint **)(*(int *)*DAT_1005b798 + -4 + uVar5 * 4);
              }
              bVar2 = RwWriteStreamChunk(param_1,0x52415354,puVar6,param_4);
              if (CONCAT31(extraout_var_40,bVar2) == 0) {
                return false;
              }
              uVar5 = uVar5 + 1;
            } while ((int)uVar5 <= (int)local_888);
          }
        }
      }
      else {
        if (param_2 < 0x5343454f) {
          if (param_2 == 0x5343454e) {
            DAT_1005b798 = FUN_10037030(DAT_1005b794);
            if (DAT_1005b798 != (int *)0x0) {
              piVar7 = FUN_10037030(DAT_1005b790);
              if (piVar7 != (int *)0x0) {
                iVar4 = (**(code **)(PTR_DAT_1005b69c + 0x34c))(0x28);
                *piVar7 = iVar4;
                if (iVar4 == 0) {
                  if (piVar7 != (int *)0x0) {
                    (**(code **)(PTR_DAT_1005b69c + 0x358))(0);
                    FUN_10037010(DAT_1005b790,piVar7);
                  }
                  piVar7 = (int *)0x0;
                }
                else {
                  piVar7[2] = 0;
                  piVar7[1] = 10;
                }
              }
              *DAT_1005b798 = (int)piVar7;
              piVar7 = FUN_10037030(DAT_1005b790);
              if (piVar7 != (int *)0x0) {
                iVar4 = (**(code **)(PTR_DAT_1005b69c + 0x34c))(0x28);
                *piVar7 = iVar4;
                if (iVar4 == 0) {
                  if (piVar7 != (int *)0x0) {
                    (**(code **)(PTR_DAT_1005b69c + 0x358))(0);
                    FUN_10037010(DAT_1005b790,piVar7);
                  }
                  piVar7 = (int *)0x0;
                }
                else {
                  piVar7[2] = 0;
                  piVar7[1] = 10;
                }
              }
              DAT_1005b798[1] = (int)piVar7;
              piVar7 = FUN_10037030(DAT_1005b790);
              if (piVar7 != (int *)0x0) {
                iVar4 = (**(code **)(PTR_DAT_1005b69c + 0x34c))(0x28);
                *piVar7 = iVar4;
                if (iVar4 == 0) {
                  if (piVar7 != (int *)0x0) {
                    (**(code **)(PTR_DAT_1005b69c + 0x358))(0);
                    FUN_10037010(DAT_1005b790,piVar7);
                  }
                  piVar7 = (int *)0x0;
                }
                else {
                  piVar7[2] = 0;
                  piVar7[1] = 10;
                }
              }
              DAT_1005b798[2] = (int)piVar7;
              piVar7 = FUN_10037030(DAT_1005b790);
              if (piVar7 != (int *)0x0) {
                iVar4 = (**(code **)(PTR_DAT_1005b69c + 0x34c))(0x28);
                *piVar7 = iVar4;
                if (iVar4 == 0) {
                  if (piVar7 != (int *)0x0) {
                    (**(code **)(PTR_DAT_1005b69c + 0x358))(0);
                    FUN_10037010(DAT_1005b790,piVar7);
                  }
                  piVar7 = (int *)0x0;
                }
                else {
                  piVar7[2] = 0;
                  piVar7[1] = 10;
                }
              }
              DAT_1005b798[3] = (int)piVar7;
              piVar7 = FUN_10037030(DAT_1005b790);
              if (piVar7 != (int *)0x0) {
                iVar4 = (**(code **)(PTR_DAT_1005b69c + 0x34c))(0x28);
                *piVar7 = iVar4;
                if (iVar4 == 0) {
                  if (piVar7 != (int *)0x0) {
                    (**(code **)(PTR_DAT_1005b69c + 0x358))(0);
                    FUN_10037010(DAT_1005b790,piVar7);
                  }
                  piVar7 = (int *)0x0;
                }
                else {
                  piVar7[2] = 0;
                  piVar7[1] = 10;
                }
              }
              DAT_1005b798[4] = (int)piVar7;
              DAT_1005b798[5] = 0;
              if (((*DAT_1005b798 != 0) && (DAT_1005b798[1] != 0)) &&
                 ((DAT_1005b798[2] != 0 && ((DAT_1005b798[3] != 0 && (DAT_1005b798[4] != 0)))))) {
                iVar4 = RwForAllClumpsInScenePointer((int)param_3,&LAB_1003e3c0,DAT_1005b798[3]);
                if (iVar4 == 0) {
                  FUN_1003d550();
                  return false;
                }
                iVar4 = RwForAllLightsInScenePointer((int)param_3,FUN_1003e440,DAT_1005b798[4]);
                if (iVar4 == 0) {
                  FUN_1003d550();
                  return false;
                }
                FUN_1003e4c0();
                iVar4 = RwGetChunkSize(0x5343454e,(int *)param_3,(uint)param_4);
                uVar5 = iVar4 - 8;
                local_800 = 8.273809e+08;
                local_7fc = (uVar5 & 0xff00 | uVar5 * 0x10000) << 8 |
                            (uVar5 & 0xff0000 | uVar5 >> 0x10) >> 8;
                bVar2 = RwWriteStream(param_1,&local_800,8);
                if (CONCAT31(extraout_var_46,bVar2) == 0) {
                  FUN_1003d550();
                  return false;
                }
                bVar2 = RwWriteStreamChunk(param_1,0x52414c54,(uint *)0x0,param_4);
                if (CONCAT31(extraout_var_47,bVar2) == 0) {
                  bVar2 = false;
                }
                else {
                  bVar3 = RwWriteStreamChunk(param_1,0x54454c54,(uint *)0x0,param_4);
                  bVar2 = false;
                  if (CONCAT31(extraout_var_48,bVar3) != 0) {
                    bVar2 = RwWriteStreamChunk(param_1,0x4d414c54,(uint *)0x0,param_4);
                    bVar2 = CONCAT31(extraout_var_49,bVar2) != 0;
                  }
                }
                if (bVar2) {
                  iVar4 = 1;
                  local_888 = *(float *)(DAT_1005b798[4] + 8);
                  pfVar9 = &local_888;
                  do {
                    fVar18 = *pfVar9;
                    iVar4 = iVar4 + -1;
                    *pfVar9 = (float)(((uint)fVar18 & 0xff00 | (int)fVar18 << 0x10) << 8 |
                                     ((uint)fVar18 & 0xff0000 | (uint)fVar18 >> 0x10) >> 8);
                    pfVar9 = pfVar9 + 1;
                  } while (iVar4 != 0);
                  bVar2 = RwWriteStreamChunk(param_1,0x53545254,(uint *)&local_888,5.60519e-45);
                  if (CONCAT31(extraout_var_50,bVar2) == 0) {
                    FUN_1003d550();
                    return false;
                  }
                  uVar5 = 1;
                  if (0 < *(int *)(DAT_1005b798[4] + 8)) {
                    do {
                      if (((uint)((int *)DAT_1005b798[4])[2] < uVar5) || (uVar5 == 0)) {
                        puVar6 = (uint *)0x0;
                      }
                      else {
                        puVar6 = *(uint **)(*(int *)DAT_1005b798[4] + -4 + uVar5 * 4);
                      }
                      bVar2 = RwWriteStreamChunk(param_1,0x4c495445,puVar6,param_4);
                      if (CONCAT31(extraout_var_51,bVar2) == 0) {
                        FUN_1003d550();
                        return false;
                      }
                      uVar5 = uVar5 + 1;
                    } while ((int)uVar5 <= *(int *)(DAT_1005b798[4] + 8));
                  }
                  local_888 = *(float *)(DAT_1005b798[3] + 8);
                  iVar4 = 1;
                  pfVar9 = &local_888;
                  do {
                    fVar18 = *pfVar9;
                    iVar4 = iVar4 + -1;
                    *pfVar9 = (float)(((uint)fVar18 & 0xff00 | (int)fVar18 << 0x10) << 8 |
                                     ((uint)fVar18 & 0xff0000 | (uint)fVar18 >> 0x10) >> 8);
                    pfVar9 = pfVar9 + 1;
                  } while (iVar4 != 0);
                  bVar2 = RwWriteStreamChunk(param_1,0x53545254,(uint *)&local_888,5.60519e-45);
                  if (CONCAT31(extraout_var_52,bVar2) == 0) {
                    FUN_1003d550();
                    return false;
                  }
                  uVar5 = 1;
                  if (0 < *(int *)(DAT_1005b798[3] + 8)) {
                    do {
                      if (((uint)((int *)DAT_1005b798[3])[2] < uVar5) || (uVar5 == 0)) {
                        puVar6 = (uint *)0x0;
                      }
                      else {
                        puVar6 = *(uint **)(*(int *)DAT_1005b798[3] + -4 + uVar5 * 4);
                      }
                      bVar2 = RwWriteStreamChunk(param_1,0x41544f4d,puVar6,param_4);
                      if (CONCAT31(extraout_var_53,bVar2) == 0) {
                        FUN_1003d550();
                        return false;
                      }
                      uVar5 = uVar5 + 1;
                    } while ((int)uVar5 <= *(int *)(DAT_1005b798[3] + 8));
                  }
                  FUN_1003d550();
                  return true;
                }
                FUN_1003d550();
                return false;
              }
              FUN_1003d550();
            }
            return false;
          }
          if (param_2 == 0x52454354) {
            if (param_3 == (uint *)0x0) {
              FUN_1000cba0(1);
              return false;
            }
            iVar4 = RwGetChunkSize(0x52454354,(int *)param_3,(uint)param_4);
            uVar5 = iVar4 - 8;
            local_800 = 3.3547265e+12;
            local_7fc = (uVar5 & 0xff00 | uVar5 * 0x10000) << 8 |
                        (uVar5 & 0xff0000 | uVar5 >> 0x10) >> 8;
            bVar2 = RwWriteStream(param_1,&local_800,8);
            if (CONCAT31(extraout_var_44,bVar2) != 0) {
              local_874[0] = (float)*param_3;
              local_874[1] = (float)param_3[1];
              iVar4 = 4;
              local_874[2] = (float)param_3[2];
              local_874[3] = (float)param_3[3];
              pfVar9 = local_874;
              do {
                fVar18 = *pfVar9;
                iVar4 = iVar4 + -1;
                *pfVar9 = (float)(((uint)fVar18 & 0xff00 | (int)fVar18 << 0x10) << 8 |
                                 ((uint)fVar18 & 0xff0000 | (uint)fVar18 >> 0x10) >> 8);
                pfVar9 = pfVar9 + 1;
              } while (iVar4 != 0);
              bVar2 = RwWriteStreamChunk(param_1,0x53545254,(uint *)local_874,2.24208e-44);
              return (bool)('\x01' - (CONCAT31(extraout_var_45,bVar2) == 0));
            }
            return false;
          }
          goto LAB_1003e8c4;
        }
        if (param_2 < 0x53545255) {
          if (param_2 == 0x53545254) {
            iVar4 = RwGetChunkSize(0x53545254,(int *)param_3,(uint)param_4);
            uVar5 = iVar4 - 8;
            local_800 = 3.6134314e+12;
            local_7fc = (uVar5 & 0xff00 | uVar5 * 0x10000) << 8 |
                        (uVar5 & 0xff0000 | uVar5 >> 0x10) >> 8;
            bVar2 = RwWriteStream(param_1,&local_800,8);
            if (CONCAT31(extraout_var_56,bVar2) != 0) {
              bVar2 = RwWriteStream(param_1,param_3,(uint)param_4);
              return (bool)('\x01' - (CONCAT31(extraout_var_57,bVar2) == 0));
            }
            return false;
          }
          if (param_2 != 0x53544e47) goto LAB_1003e8c4;
          iVar4 = RwGetChunkSize(0x53544e47,(int *)param_3,(uint)param_4);
          uVar5 = iVar4 - 8;
          local_800 = 52820.324;
          local_7fc = (uVar5 & 0xff00 | uVar5 * 0x10000) << 8 |
                      (uVar5 & 0xff0000 | uVar5 >> 0x10) >> 8;
          bVar2 = RwWriteStream(param_1,&local_800,8);
          if (CONCAT31(extraout_var_54,bVar2) == 0) {
            return false;
          }
          if (param_3 != (uint *)0x0) {
            iVar4 = RwGetChunkSize(0x53544e47,(int *)param_3,(uint)param_4);
            bVar2 = RwWriteStream(param_1,param_3,iVar4 - 8);
            if (CONCAT31(extraout_var_55,bVar2) == 0) {
              return false;
            }
          }
        }
        else if (param_2 < 0x54455856) {
          if (param_2 == 0x54455855) {
            if (param_3 == (uint *)0x0) {
              FUN_1000cba0(1);
              return false;
            }
            iVar4 = RwGetChunkSize(0x54455855,(int *)param_3,(uint)param_4);
            uVar5 = iVar4 - 8;
            local_800 = 1.4862017e+13;
            local_7fc = (uVar5 & 0xff00 | uVar5 * 0x10000) << 8 |
                        (uVar5 & 0xff0000 | uVar5 >> 0x10) >> 8;
            bVar2 = RwWriteStream(param_1,&local_800,8);
            if (CONCAT31(extraout_var_62,bVar2) == 0) {
              return false;
            }
            uVar5 = (uint)param_4 & 8;
            local_874[0] = (float)(uint)(uVar5 != 0);
            if ((uVar5 == 0) || (param_3[7] == 0)) {
              local_874[1] = 0.0;
            }
            else {
              local_874[1] = 1.4013e-45;
            }
            iVar4 = FUN_10018570((int *)param_3);
            if ((iVar4 == 0) && (local_874[0] == 0.0)) {
              FUN_1000cba0(0x5d);
              return false;
            }
            local_874[2] = (float)RwGetTextureNumFrames((int)param_3);
            local_874[3] = (float)RwGetTextureFrame((int)param_3);
            local_864 = RwGetTextureFrameStep((int)param_3);
            local_800 = 7.00649e-45;
            pfVar9 = local_874;
            do {
              fVar18 = *pfVar9;
              *pfVar9 = (float)(((uint)fVar18 & 0xff00 | (int)fVar18 << 0x10) << 8 |
                               ((uint)fVar18 & 0xff0000 | (uint)fVar18 >> 0x10) >> 8);
              local_800 = (float)((int)local_800 - 1);
              pfVar9 = pfVar9 + 1;
            } while (local_800 != 0.0);
            bVar2 = RwWriteStreamChunk(param_1,0x53545254,(uint *)local_874,2.8026e-44);
            if (CONCAT31(extraout_var_63,bVar2) == 0) {
              return false;
            }
            fVar18 = 0.0;
            puVar6 = (uint *)FUN_10018570((int *)param_3);
            bVar2 = RwWriteStreamChunk(param_1,0x53544e47,puVar6,fVar18);
            if (CONCAT31(extraout_var_64,bVar2) == 0) {
              return false;
            }
            if (uVar5 != 0) {
              bVar2 = RwWriteStreamChunk(param_1,0x52415354,(uint *)param_3[6],0.0);
              if (CONCAT31(extraout_var_65,bVar2) == 0) {
                return false;
              }
              if (((uVar5 != 0) && ((uint *)param_3[7] != (uint *)0x0)) &&
                 (bVar2 = RwWriteStreamChunk(param_1,0x52415354,(uint *)param_3[7],0.0),
                 CONCAT31(extraout_var_66,bVar2) == 0)) {
                return false;
              }
            }
          }
          else {
            if (param_2 != 0x54454c54) goto LAB_1003e8c4;
            iVar4 = RwGetChunkSize(0x54454c54,(int *)param_3,(uint)param_4);
            uVar5 = iVar4 - 8;
            local_800 = 3.5093458e+12;
            local_7fc = (uVar5 & 0xff0000 | uVar5 >> 0x10) >> 8 |
                        (uVar5 & 0xff00 | uVar5 * 0x10000) << 8;
            bVar2 = RwWriteStream(param_1,&local_800,8);
            if (CONCAT31(extraout_var_58,bVar2) == 0) {
              return false;
            }
            iVar4 = 3;
            local_888 = *(float *)(DAT_1005b798[1] + 8);
            local_874[0] = *(float *)(DAT_1005b798[1] + 8);
            local_874[1] = 2.8026e-44;
            local_874[2] = param_4;
            pfVar9 = local_874;
            do {
              fVar18 = *pfVar9;
              iVar4 = iVar4 + -1;
              *pfVar9 = (float)(((uint)fVar18 & 0xff00 | (int)fVar18 << 0x10) << 8 |
                               ((uint)fVar18 & 0xff0000 | (uint)fVar18 >> 0x10) >> 8);
              pfVar9 = pfVar9 + 1;
            } while (iVar4 != 0);
            bVar2 = RwWriteStreamChunk(param_1,0x53545254,(uint *)local_874,1.68156e-44);
            if (CONCAT31(extraout_var_59,bVar2) == 0) {
              return false;
            }
            uStack_884 = 1;
            if (0 < (int)local_888) {
              local_800 = (float)((uint)param_4 & 8);
              do {
                if (((uint)((int *)DAT_1005b798[1])[2] < uStack_884) || (uStack_884 == 0)) {
                  piVar7 = (int *)0x0;
                }
                else {
                  piVar7 = *(int **)(*(int *)DAT_1005b798[1] + -4 + uStack_884 * 4);
                }
                local_874[2] = (float)RwGetTextureNumFrames((int)piVar7);
                local_874[3] = (float)RwGetTextureFrame((int)piVar7);
                local_864 = RwGetTextureFrameStep((int)piVar7);
                if (local_800 == 0.0) {
LAB_10040b94:
                  local_874[0] = 0.0;
                }
                else {
                  if (piVar7[6] == 0) goto LAB_10040b94;
                  piVar11 = *(int **)*DAT_1005b798;
                  uVar10 = 0;
                  uVar5 = ((undefined4 *)*DAT_1005b798)[2];
                  if (uVar5 != 0) {
                    do {
                      if (*piVar11 == piVar7[6]) {
                        local_874[0] = (float)(uVar10 + 1);
                        break;
                      }
                      piVar11 = piVar11 + 1;
                      uVar10 = uVar10 + 1;
                    } while (uVar10 < uVar5);
                  }
                }
                if ((local_800 == 0.0) || (piVar7[7] == 0)) {
                  local_874[1] = 0.0;
                }
                else {
                  uVar10 = 0;
                  piVar11 = *(int **)*DAT_1005b798;
                  uVar5 = ((undefined4 *)*DAT_1005b798)[2];
                  if (uVar5 != 0) {
                    do {
                      if (*piVar11 == piVar7[7]) {
                        local_874[1] = (float)(uVar10 + 1);
                        break;
                      }
                      piVar11 = piVar11 + 1;
                      uVar10 = uVar10 + 1;
                    } while (uVar10 < uVar5);
                  }
                }
                local_400 = 5;
                pfVar9 = local_874;
                do {
                  fVar18 = *pfVar9;
                  *pfVar9 = (float)(((uint)fVar18 & 0xff00 | (int)fVar18 << 0x10) << 8 |
                                   ((uint)fVar18 & 0xff0000 | (uint)fVar18 >> 0x10) >> 8);
                  local_400 = local_400 + -1;
                  pfVar9 = pfVar9 + 1;
                } while (local_400 != 0);
                bVar2 = RwWriteStream(param_1,local_874,0x14);
                if (CONCAT31(extraout_var_60,bVar2) == 0) {
                  return false;
                }
                fVar18 = param_4;
                puVar6 = (uint *)FUN_10018570(piVar7);
                bVar2 = RwWriteStreamChunk(param_1,0x53544e47,puVar6,fVar18);
                if (CONCAT31(extraout_var_61,bVar2) == 0) {
                  return false;
                }
                uStack_884 = uStack_884 + 1;
              } while ((int)uStack_884 <= (int)local_888);
            }
          }
        }
        else {
          if (param_2 == 0x56334420) {
            if (param_3 == (uint *)0x0) {
              FUN_1000cba0(1);
              return false;
            }
            iVar4 = RwGetChunkSize(0x56334420,(int *)param_3,(uint)param_4);
            uVar5 = iVar4 - 8;
            local_800 = 1.6618831e-19;
            local_7fc = (uVar5 & 0xff00 | uVar5 * 0x10000) << 8 |
                        (uVar5 & 0xff0000 | uVar5 >> 0x10) >> 8;
            bVar2 = RwWriteStream(param_1,&local_800,8);
            if (CONCAT31(extraout_var_67,bVar2) != 0) {
              iVar4 = 3;
              local_874[0] = (float)*param_3;
              local_874[1] = (float)param_3[1];
              local_874[2] = (float)param_3[2];
              pfVar9 = local_874;
              do {
                fVar18 = *pfVar9;
                iVar4 = iVar4 + -1;
                *pfVar9 = (float)(((uint)fVar18 & 0xff00 | (int)fVar18 << 0x10) << 8 |
                                 ((uint)fVar18 & 0xff0000 | (uint)fVar18 >> 0x10) >> 8);
                pfVar9 = pfVar9 + 1;
              } while (iVar4 != 0);
              bVar2 = RwWriteStreamChunk(param_1,0x53545254,(uint *)local_874,1.68156e-44);
              return (bool)('\x01' - (CONCAT31(extraout_var_68,bVar2) == 0));
            }
            return false;
          }
          if (param_2 != 0x564c5354) goto LAB_1003e8c4;
          local_878 = param_3[0x22];
          iVar4 = RwGetChunkSize(0x564c5354,(int *)param_3,(uint)param_4);
          uVar5 = iVar4 - 8;
          local_800 = 3.6300752e+12;
          local_7fc = (uVar5 & 0xff00 | uVar5 * 0x10000) << 8 |
                      (uVar5 & 0xff0000 | uVar5 >> 0x10) >> 8;
          bVar2 = RwWriteStream(param_1,&local_800,8);
          if (CONCAT31(extraout_var_69,bVar2) == 0) {
            return false;
          }
          local_874[0] = *(float *)(local_878 + 8);
          local_880 = (float)((uint)param_4 & 2);
          local_818 = (uint)param_4 & 4;
          local_400 = (uint)param_4 & 1;
          iVar4 = 3;
          local_874[1] = (float)(((((uint)param_4 & 4) == 0) - 1 & 0xc) +
                                 ((((uint)param_4 & 1) == 0) - 1 & 0xc) +
                                 (((float)((uint)param_4 & 2) == 0.0) - 1 & 8) + 0xc);
          local_874[2] = param_4;
          pfVar9 = local_874;
          do {
            fVar18 = *pfVar9;
            iVar4 = iVar4 + -1;
            *pfVar9 = (float)(((uint)fVar18 & 0xff00 | (int)fVar18 << 0x10) << 8 |
                             ((uint)fVar18 & 0xff0000 | (uint)fVar18 >> 0x10) >> 8);
            pfVar9 = pfVar9 + 1;
          } while (iVar4 != 0);
          bVar2 = RwWriteStreamChunk(param_1,0x53545254,(uint *)local_874,1.68156e-44);
          if (CONCAT31(extraout_var_70,bVar2) == 0) {
            return false;
          }
          uStack_884 = 0;
          if (0 < *(int *)(local_878 + 8)) {
            pfVar9 = (float *)(local_878 + 0xc);
            do {
              local_874[0] = *pfVar9;
              iVar4 = 3;
              local_874[1] = pfVar9[1];
              local_874[2] = pfVar9[2];
              pfVar12 = local_874;
              do {
                fVar18 = *pfVar12;
                iVar4 = iVar4 + -1;
                *pfVar12 = (float)(((uint)fVar18 & 0xff00 | (int)fVar18 << 0x10) << 8 |
                                  ((uint)fVar18 & 0xff0000 | (uint)fVar18 >> 0x10) >> 8);
                pfVar12 = pfVar12 + 1;
              } while (iVar4 != 0);
              bVar2 = RwWriteStream(param_1,local_874,0xc);
              if (CONCAT31(extraout_var_71,bVar2) == 0) {
                return false;
              }
              if (local_400 != 0) {
                local_874[0] = pfVar9[0x13];
                iVar4 = 3;
                local_874[1] = pfVar9[0x14];
                local_874[2] = pfVar9[0x15];
                pfVar12 = local_874;
                do {
                  fVar18 = *pfVar12;
                  iVar4 = iVar4 + -1;
                  *pfVar12 = (float)(((uint)fVar18 & 0xff00 | (int)fVar18 << 0x10) << 8 |
                                    ((uint)fVar18 & 0xff0000 | (uint)fVar18 >> 0x10) >> 8);
                  pfVar12 = pfVar12 + 1;
                } while (iVar4 != 0);
                bVar2 = RwWriteStream(param_1,local_874,0xc);
                if (CONCAT31(extraout_var_72,bVar2) == 0) {
                  return false;
                }
              }
              if (local_880 != 0.0) {
                local_874[0] = (float)(int)pfVar9[0x19] * (float)_DAT_100522a8;
                local_800 = pfVar9[0x1a];
                iVar4 = 2;
                local_874[1] = (float)(int)pfVar9[0x1a] * (float)_DAT_100522a8;
                pfVar12 = local_874;
                do {
                  fVar18 = *pfVar12;
                  iVar4 = iVar4 + -1;
                  *pfVar12 = (float)(((uint)fVar18 & 0xff00 | (int)fVar18 << 0x10) << 8 |
                                    ((uint)fVar18 & 0xff0000 | (uint)fVar18 >> 0x10) >> 8);
                  pfVar12 = pfVar12 + 1;
                } while (iVar4 != 0);
                bVar2 = RwWriteStream(param_1,local_874,8);
                if (CONCAT31(extraout_var_73,bVar2) == 0) {
                  return false;
                }
              }
              if (local_818 != 0) {
                local_874[0] = (float)(int)pfVar9[0x16] * (float)_DAT_100522a8;
                local_874[1] = (float)(int)pfVar9[0x17] * (float)_DAT_100522a8;
                iVar4 = 3;
                local_800 = pfVar9[0x18];
                local_874[2] = (float)(int)pfVar9[0x18] * (float)_DAT_100522a8;
                pfVar12 = local_874;
                do {
                  fVar18 = *pfVar12;
                  iVar4 = iVar4 + -1;
                  *pfVar12 = (float)(((uint)fVar18 & 0xff00 | (int)fVar18 << 0x10) << 8 |
                                    ((uint)fVar18 & 0xff0000 | (uint)fVar18 >> 0x10) >> 8);
                  pfVar12 = pfVar12 + 1;
                } while (iVar4 != 0);
                bVar2 = RwWriteStream(param_1,local_874,0xc);
                if (CONCAT31(extraout_var_74,bVar2) == 0) {
                  return false;
                }
              }
              pfVar9 = pfVar9 + 0x1d;
              uStack_884 = uStack_884 + 1;
            } while ((int)uStack_884 < *(int *)(local_878 + 8));
          }
        }
      }
      return true;
    }
    if (param_2 == 0x44415441) {
      if (param_3 == (uint *)0x0) {
        FUN_1000cba0(1);
        return false;
      }
      iVar4 = RwGetChunkSize(0x44415441,(int *)param_3,(uint)param_4);
      uVar5 = iVar4 - 8;
      local_800 = 13.265934;
      local_7fc = (uVar5 >> 0x10 | uVar5 & 0xff0000) >> 8 | (uVar5 * 0x10000 | uVar5 & 0xff00) << 8;
      bVar2 = RwWriteStream(param_1,&local_800,8);
      if (CONCAT31(extraout_var_16,bVar2) != 0) {
        iVar4 = RwGetChunkSize(0x44415441,(int *)param_3,(uint)param_4);
        bVar2 = RwWriteStream(param_1,(undefined4 *)*param_3,iVar4 - 8);
        return (bool)('\x01' - (CONCAT31(extraout_var_17,bVar2) == 0));
      }
      return false;
    }
    if (param_2 == 0x434c554d) {
      puVar6 = (uint *)RwGetClumpRoot((int)param_3);
      if (puVar6 != param_3) {
        return false;
      }
      DAT_1005b798 = FUN_10037030(DAT_1005b794);
      if (DAT_1005b798 != (int *)0x0) {
        piVar7 = FUN_10037030(DAT_1005b790);
        if (piVar7 != (int *)0x0) {
          iVar4 = (**(code **)(PTR_DAT_1005b69c + 0x34c))(0x28);
          *piVar7 = iVar4;
          if (iVar4 == 0) {
            if (piVar7 != (int *)0x0) {
              (**(code **)(PTR_DAT_1005b69c + 0x358))(0);
              FUN_10037010(DAT_1005b790,piVar7);
            }
            piVar7 = (int *)0x0;
          }
          else {
            piVar7[2] = 0;
            piVar7[1] = 10;
          }
        }
        *DAT_1005b798 = (int)piVar7;
        piVar7 = FUN_10037030(DAT_1005b790);
        if (piVar7 != (int *)0x0) {
          iVar4 = (**(code **)(PTR_DAT_1005b69c + 0x34c))(0x28);
          *piVar7 = iVar4;
          if (iVar4 == 0) {
            if (piVar7 != (int *)0x0) {
              (**(code **)(PTR_DAT_1005b69c + 0x358))(0);
              FUN_10037010(DAT_1005b790,piVar7);
            }
            piVar7 = (int *)0x0;
          }
          else {
            piVar7[2] = 0;
            piVar7[1] = 10;
          }
        }
        DAT_1005b798[1] = (int)piVar7;
        piVar7 = FUN_10037030(DAT_1005b790);
        if (piVar7 != (int *)0x0) {
          iVar4 = (**(code **)(PTR_DAT_1005b69c + 0x34c))(0x28);
          *piVar7 = iVar4;
          if (iVar4 == 0) {
            if (piVar7 != (int *)0x0) {
              (**(code **)(PTR_DAT_1005b69c + 0x358))(0);
              FUN_10037010(DAT_1005b790,piVar7);
            }
            piVar7 = (int *)0x0;
          }
          else {
            piVar7[2] = 0;
            piVar7[1] = 10;
          }
        }
        DAT_1005b798[2] = (int)piVar7;
        piVar7 = FUN_10037030(DAT_1005b790);
        if (piVar7 != (int *)0x0) {
          iVar4 = (**(code **)(PTR_DAT_1005b69c + 0x34c))(0x28);
          *piVar7 = iVar4;
          if (iVar4 == 0) {
            if (piVar7 != (int *)0x0) {
              (**(code **)(PTR_DAT_1005b69c + 0x358))(0);
              FUN_10037010(DAT_1005b790,piVar7);
            }
            piVar7 = (int *)0x0;
          }
          else {
            piVar7[2] = 0;
            piVar7[1] = 10;
          }
        }
        DAT_1005b798[3] = (int)piVar7;
        piVar7 = FUN_10037030(DAT_1005b790);
        if (piVar7 != (int *)0x0) {
          iVar4 = (**(code **)(PTR_DAT_1005b69c + 0x34c))(0x28);
          *piVar7 = iVar4;
          if (iVar4 == 0) {
            if (piVar7 != (int *)0x0) {
              (**(code **)(PTR_DAT_1005b69c + 0x358))(0);
              FUN_10037010(DAT_1005b790,piVar7);
            }
            piVar7 = (int *)0x0;
          }
          else {
            piVar7[2] = 0;
            piVar7[1] = 10;
          }
        }
        DAT_1005b798[4] = (int)piVar7;
        DAT_1005b798[5] = 0;
        if ((((*DAT_1005b798 != 0) && (DAT_1005b798[1] != 0)) && (DAT_1005b798[2] != 0)) &&
           ((DAT_1005b798[3] != 0 && (DAT_1005b798[4] != 0)))) {
          piVar11 = (int *)DAT_1005b798[3];
          piVar7 = (int *)(*piVar11 + piVar11[2] * 4);
          iVar4 = piVar11[2];
          do {
            piVar7 = piVar7 + -1;
            if (iVar4 == 0) {
              uVar5 = piVar11[1];
              if (uVar5 <= (uint)piVar11[2]) {
                iVar4 = (**(code **)(PTR_DAT_1005b69c + 0x354))(*piVar11,uVar5 * 4 + 0xa0);
                if (iVar4 == 0) {
                  bVar2 = false;
                  goto LAB_1003f007;
                }
                *piVar11 = iVar4;
                piVar11[1] = uVar5 + 0x28;
              }
              *(uint **)(*piVar11 + piVar11[2] * 4) = param_3;
              piVar11[2] = piVar11[2] + 1;
              break;
            }
            iVar4 = iVar4 + -1;
          } while ((uint *)*piVar7 != param_3);
          bVar2 = true;
LAB_1003f007:
          if (!bVar2) {
            FUN_1003d550();
            return false;
          }
          FUN_1003e4c0();
          iVar4 = RwGetChunkSize(0x434c554d,(int *)param_3,(uint)param_4);
          uVar5 = iVar4 - 8;
          local_800 = 2.2365906e+08;
          local_7fc = (uVar5 & 0xff00 | uVar5 * 0x10000) << 8 |
                      (uVar5 & 0xff0000 | uVar5 >> 0x10) >> 8;
          bVar2 = RwWriteStream(param_1,&local_800,8);
          if (CONCAT31(extraout_var_11,bVar2) != 0) {
            bVar2 = RwWriteStreamChunk(param_1,0x52414c54,(uint *)0x0,param_4);
            if (CONCAT31(extraout_var_12,bVar2) == 0) {
              bVar2 = false;
            }
            else {
              bVar3 = RwWriteStreamChunk(param_1,0x54454c54,(uint *)0x0,param_4);
              bVar2 = false;
              if (CONCAT31(extraout_var_13,bVar3) != 0) {
                bVar2 = RwWriteStreamChunk(param_1,0x4d414c54,(uint *)0x0,param_4);
                bVar2 = CONCAT31(extraout_var_14,bVar2) != 0;
              }
            }
            if (bVar2) {
              bVar2 = RwWriteStreamChunk(param_1,0x41544f4d,param_3,param_4);
              if (CONCAT31(extraout_var_15,bVar2) != 0) {
                FUN_1003d550();
                return true;
              }
              FUN_1003d550();
              return false;
            }
            FUN_1003d550();
            return false;
          }
          FUN_1003d550();
          return false;
        }
        FUN_1003d550();
      }
      return false;
    }
  }
LAB_1003e8c4:
  FUN_1000cba0(0x59);
  return false;
}


