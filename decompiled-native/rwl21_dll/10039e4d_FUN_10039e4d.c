// 10039e4d FUN_10039e4d [Global]
// programa: RWL21.DLL

bool FUN_10039e4d(uint **param_1,uint param_2,uint param_3,uint param_4,uint param_5,uint param_6,
                 uint param_7,uint **param_8,uint **param_9,uint **param_10,uint **param_11,
                 uint **param_12,uint **param_13,uint **param_14,uint **param_15,uint **param_16,
                 uint **param_17,uint **param_18,uint **param_19,uint **param_20,uint **param_21,
                 undefined4 param_22,float param_23,float param_24,undefined4 param_25,
                 undefined4 param_26,float param_27,float param_28,uint param_29,uint param_30,
                 int *param_31,undefined4 param_32,undefined4 *param_33,undefined4 *param_34,
                 int *param_35,uint ****param_36,uint *param_37,undefined4 *param_38,uint param_39)

{
  uint uVar1;
  uint ****ppppuVar2;
  bool bVar3;
  bool bVar4;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar5;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  undefined3 extraout_var_05;
  undefined3 extraout_var_06;
  undefined3 extraout_var_07;
  undefined3 extraout_var_08;
  undefined4 *puVar6;
  undefined3 extraout_var_09;
  undefined3 extraout_var_10;
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
  int *piVar7;
  undefined3 extraout_var_44;
  undefined3 extraout_var_45;
  undefined3 extraout_var_46;
  undefined3 extraout_var_47;
  undefined3 extraout_var_48;
  undefined3 extraout_var_49;
  undefined3 extraout_var_50;
  undefined3 extraout_var_51;
  undefined3 extraout_var_52;
  undefined3 extraout_var_53;
  undefined3 extraout_var_54;
  undefined3 extraout_var_55;
  uint *puVar8;
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
  uint ***pppuVar9;
  undefined3 extraout_var_66;
  undefined3 extraout_var_67;
  undefined3 extraout_var_68;
  uint uVar10;
  undefined3 extraout_var_69;
  undefined3 extraout_var_70;
  undefined3 extraout_var_71;
  undefined3 extraout_var_72;
  undefined3 extraout_var_73;
  undefined3 extraout_var_74;
  undefined3 extraout_var_75;
  undefined3 extraout_var_76;
  undefined3 extraout_var_77;
  undefined3 extraout_var_78;
  undefined3 extraout_var_79;
  undefined3 extraout_var_80;
  undefined3 extraout_var_81;
  undefined3 extraout_var_82;
  undefined3 extraout_var_83;
  undefined3 extraout_var_84;
  undefined3 extraout_var_85;
  undefined3 extraout_var_86;
  undefined3 extraout_var_87;
  undefined3 extraout_var_88;
  undefined3 extraout_var_89;
  int *piVar11;
  undefined4 *puVar12;
  undefined3 extraout_var_90;
  undefined3 extraout_var_91;
  undefined3 extraout_var_92;
  undefined3 extraout_var_93;
  undefined3 extraout_var_94;
  undefined3 extraout_var_95;
  undefined3 extraout_var_96;
  undefined3 extraout_var_97;
  undefined3 extraout_var_98;
  undefined3 extraout_var_99;
  uint ***pppuVar13;
  uint **ppuVar14;
  uint uVar15;
  uint **ppuVar16;
  uint *unaff_EBX;
  undefined4 unaff_EBP;
  int *unaff_ESI;
  byte *pbVar17;
  uint *puVar18;
  uint **ppuVar19;
  undefined4 *unaff_EDI;
  int *piVar20;
  uint *puVar21;
  uint **ppuVar22;
  bool in_ZF;
  longlong lVar23;
  uint unaff_retaddr;
  undefined4 uVar24;
  
  ppppuVar2 = param_36;
  if (in_ZF) {
    FUN_1000cba0(1);
    return false;
  }
  bVar3 = RwReadStream((int *)param_36,&param_6,4);
  if (CONCAT31(extraout_var,bVar3) == 0) {
    return false;
  }
  uVar15 = (param_6 << 0x10 | param_6 & 0xff00) << 8 | (param_6 >> 0x10 | param_6 & 0xff0000) >> 8;
  param_6 = uVar15;
  if ((int)param_37 < 0x43414d46) {
    if (param_37 == (uint *)0x43414d45) {
      do {
        bVar3 = RwReadStream((int *)ppppuVar2,&param_2,4);
        if (CONCAT31(extraout_var_54,bVar3) == 0) break;
        param_2 = (param_2 & 0xff00 | param_2 << 0x10) << 8 |
                  (param_2 & 0xff0000 | param_2 >> 0x10) >> 8;
        if (param_2 == 0x53545254) {
          bVar3 = true;
          goto LAB_1003ba76;
        }
        iVar5 = RwSkipStreamChunk((int *)ppppuVar2);
      } while (iVar5 != 0);
      bVar3 = false;
LAB_1003ba76:
      if (!bVar3) {
        FUN_1000cba0(0x5a);
        return false;
      }
      bVar3 = RwReadStreamChunk(ppppuVar2,0x53545254,(int *)&param_10);
      if (CONCAT31(extraout_var_55,bVar3) == 0) {
        return false;
      }
      iVar5 = 0x17;
      pppuVar9 = &param_9;
      do {
        ppuVar16 = *pppuVar9;
        iVar5 = iVar5 + -1;
        *pppuVar9 = (uint **)(((uint)ppuVar16 & 0xff00 | (int)ppuVar16 << 0x10) << 8 |
                             ((uint)ppuVar16 & 0xff0000 | (uint)ppuVar16 >> 0x10) >> 8);
        pppuVar9 = pppuVar9 + 1;
      } while (iVar5 != 0);
      puVar8 = RwCreateCamera(param_20,param_21,(undefined4 *)0x0);
      if (puVar8 == (uint *)0x0) {
        return false;
      }
      RwSetCameraProjection((int)puVar8,(int)param_9);
      RwSetCameraBackColor((uint)puVar8,param_29,param_30,(uint)param_31);
      RwSetCameraNearClipping((int)puVar8,param_23);
      RwSetCameraFarClipping((int)puVar8,param_24);
      RwSetCameraBackdropOffset((int)puVar8,param_10,param_11);
      RwSetCameraBackdropViewportRect
                ((int)puVar8,(int)param_12,(int)param_13,(int)param_14,(int)param_15);
      RwSetCameraViewport((int)puVar8,(int)param_16,(int)param_17,(int)param_18,(int)param_19);
      RwSetCameraViewwindow((int)puVar8,param_27,param_28);
      do {
        bVar3 = RwReadStream((int *)ppppuVar2,&param_1,4);
        if (CONCAT31(extraout_var_56,bVar3) == 0) break;
        param_1 = (uint **)(((uint)param_1 & 0xff00 | (int)param_1 << 0x10) << 8 |
                           ((uint)param_1 & 0xff0000 | (uint)param_1 >> 0x10) >> 8);
        if (param_1 == (uint **)0x4d415458) {
          bVar3 = true;
          goto LAB_1003bbf6;
        }
        iVar5 = RwSkipStreamChunk((int *)ppppuVar2);
      } while (iVar5 != 0);
      bVar3 = false;
LAB_1003bbf6:
      if (!bVar3) {
        RwDestroyCamera(puVar8);
        FUN_1000cba0(0x5a);
        return false;
      }
      bVar3 = RwReadStreamChunk(ppppuVar2,0x4d415458,(int *)&stack0x00000000);
      if (CONCAT31(extraout_var_57,bVar3) == 0) {
        RwDestroyCamera(puVar8);
        return false;
      }
      puVar18 = unaff_EBX;
      puVar21 = puVar8;
      for (iVar5 = 0x11; puVar21 = puVar21 + 1, iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar21 = *puVar18;
        puVar18 = puVar18 + 1;
      }
      RwDestroyMatrix(unaff_EBX);
      do {
        bVar3 = RwReadStream((int *)ppppuVar2,(undefined4 *)&stack0x00000000,4);
        if (CONCAT31(extraout_var_58,bVar3) == 0) break;
        unaff_retaddr =
             (unaff_retaddr & 0xff00 | unaff_retaddr << 0x10) << 8 |
             (unaff_retaddr & 0xff0000 | unaff_retaddr >> 0x10) >> 8;
        if (unaff_retaddr == 0x56334420) {
          bVar3 = true;
          goto LAB_1003bcac;
        }
        iVar5 = RwSkipStreamChunk((int *)ppppuVar2);
      } while (iVar5 != 0);
      bVar3 = false;
LAB_1003bcac:
      if (!bVar3) {
        RwDestroyCamera(puVar8);
        FUN_1000cba0(0x5a);
        return false;
      }
      bVar3 = RwReadStreamChunk(ppppuVar2,0x56334420,(int *)&param_1);
      if (CONCAT31(extraout_var_59,bVar3) == 0) {
        RwDestroyCamera(puVar8);
        return false;
      }
      RwSetCameraViewOffset((int)puVar8,unaff_retaddr,param_1);
      if (param_20 != (uint **)0x0) {
        do {
          bVar3 = RwReadStream((int *)ppppuVar2,(undefined4 *)&stack0xfffffffc,4);
          if (CONCAT31(extraout_var_60,bVar3) == 0) break;
          unaff_EBX = (uint *)(((uint)unaff_EBX & 0xff00 | (int)unaff_EBX << 0x10) << 8 |
                              ((uint)unaff_EBX & 0xff0000 | (uint)unaff_EBX >> 0x10) >> 8);
          if (unaff_EBX == (uint *)0x52415354) {
            bVar3 = true;
            goto LAB_1003bd66;
          }
          iVar5 = RwSkipStreamChunk((int *)ppppuVar2);
        } while (iVar5 != 0);
        bVar3 = false;
LAB_1003bd66:
        if (!bVar3) {
          RwDestroyCamera(puVar8);
          FUN_1000cba0(0x5a);
          return false;
        }
        bVar3 = RwReadStreamChunk(ppppuVar2,0x52415354,(int *)&stack0xfffffff4);
        if (CONCAT31(extraout_var_61,bVar3) == 0) {
          RwDestroyCamera(puVar8);
          return false;
        }
        RwSetCameraBackdrop((int)puVar8,unaff_EBP);
      }
      *param_34 = puVar8;
      return true;
    }
    if (param_37 == (uint *)0x41544f4d) {
      do {
        bVar3 = RwReadStream((int *)ppppuVar2,&param_3,4);
        if (CONCAT31(extraout_var_42,bVar3) == 0) break;
        param_3 = (param_3 & 0xff00 | param_3 << 0x10) << 8 |
                  (param_3 & 0xff0000 | param_3 >> 0x10) >> 8;
        if (param_3 == 0x53545254) {
          bVar3 = true;
          goto LAB_1003b5c9;
        }
        iVar5 = RwSkipStreamChunk((int *)ppppuVar2);
      } while (iVar5 != 0);
      bVar3 = false;
LAB_1003b5c9:
      if (!bVar3) {
        FUN_1000cba0(0x5a);
        return false;
      }
      uVar15 = 0x34;
      bVar3 = RwReadStreamChunk(ppppuVar2,0x53545254,(int *)&param_10);
      if (CONCAT31(extraout_var_43,bVar3) == 0) {
        return false;
      }
      iVar5 = 0xd;
      pppuVar9 = &param_9;
      do {
        ppuVar16 = *pppuVar9;
        iVar5 = iVar5 + -1;
        *pppuVar9 = (uint **)(((uint)ppuVar16 & 0xff00 | (int)ppuVar16 << 0x10) << 8 |
                             ((uint)ppuVar16 & 0xff0000 | (uint)ppuVar16 >> 0x10) >> 8);
        pppuVar9 = pppuVar9 + 1;
      } while (iVar5 != 0);
      piVar7 = RwCreateClump(0,0);
      ppuVar16 = param_17;
      if (piVar7 == (int *)0x0) {
        return false;
      }
      piVar7[0x23] = (int)param_9;
      piVar7[0x24] = (int)param_10;
      piVar7[0x3a] = (int)param_11;
      piVar7[0x62] = 0;
      piVar7[99] = (int)param_18;
      piVar7[100] = (int)param_19;
      RwSetClumpLightSampleRate((int)piVar7,(float)param_21);
      if (((uint)param_21 & 0x7fffffff) == 0) {
        *(undefined1 *)((int)piVar7 + 0x19b) = 0;
      }
      do {
        bVar3 = RwReadStream((int *)ppppuVar2,&param_2,4);
        if (CONCAT31(extraout_var_44,bVar3) == 0) break;
        param_2 = (param_2 & 0xff00 | param_2 << 0x10) << 8 |
                  (param_2 & 0xff0000 | param_2 >> 0x10) >> 8;
        if (param_2 == 0x4d415458) {
          bVar3 = true;
          goto LAB_1003b70c;
        }
        iVar5 = RwSkipStreamChunk((int *)ppppuVar2);
      } while (iVar5 != 0);
      bVar3 = false;
LAB_1003b70c:
      if (!bVar3) {
        FUN_1000cba0(0x5a);
        return false;
      }
      bVar3 = RwReadStreamChunk(ppppuVar2,0x4d415458,(int *)&stack0x00000000);
      if (CONCAT31(extraout_var_45,bVar3) == 0) {
        return false;
      }
      ppuVar19 = ppuVar16;
      piVar11 = piVar7 + 0x3b;
      for (iVar5 = 0x11; iVar5 != 0; iVar5 = iVar5 + -1) {
        *piVar11 = (int)*ppuVar19;
        ppuVar19 = ppuVar19 + 1;
        piVar11 = piVar11 + 1;
      }
      RwDestroyMatrix(ppuVar16);
      do {
        bVar3 = RwReadStream((int *)ppppuVar2,&param_1,4);
        if (CONCAT31(extraout_var_46,bVar3) == 0) break;
        param_1 = (uint **)(((uint)param_1 & 0xff00 | (int)param_1 << 0x10) << 8 |
                           ((uint)param_1 & 0xff0000 | (uint)param_1 >> 0x10) >> 8);
        if (param_1 == (uint **)0x4d415458) {
          bVar3 = true;
          goto LAB_1003b7b9;
        }
        iVar5 = RwSkipStreamChunk((int *)ppppuVar2);
      } while (iVar5 != 0);
      bVar3 = false;
LAB_1003b7b9:
      if (!bVar3) {
        FUN_1000cba0(0x5a);
        return false;
      }
      bVar3 = RwReadStreamChunk(ppppuVar2,0x4d415458,(int *)&stack0xfffffffc);
      if (CONCAT31(extraout_var_47,bVar3) == 0) {
        return false;
      }
      piVar11 = unaff_ESI;
      piVar20 = piVar7 + 0x4c;
      for (iVar5 = 0x11; iVar5 != 0; iVar5 = iVar5 + -1) {
        *piVar20 = *piVar11;
        piVar11 = piVar11 + 1;
        piVar20 = piVar20 + 1;
      }
      RwDestroyMatrix(unaff_ESI);
      do {
        bVar3 = RwReadStream((int *)ppppuVar2,(undefined4 *)&stack0x00000000,4);
        if (CONCAT31(extraout_var_48,bVar3) == 0) break;
        unaff_retaddr =
             (unaff_retaddr >> 0x10 | unaff_retaddr & 0xff0000) >> 8 |
             (unaff_retaddr << 0x10 | unaff_retaddr & 0xff00) << 8;
        if (unaff_retaddr == 0x564c5354) {
          bVar3 = true;
          goto LAB_1003b866;
        }
        iVar5 = RwSkipStreamChunk((int *)ppppuVar2);
      } while (iVar5 != 0);
      bVar3 = false;
LAB_1003b866:
      if (!bVar3) {
        FUN_1000cba0(0x5a);
        return false;
      }
      bVar3 = RwReadStreamChunk(ppppuVar2,0x564c5354,piVar7);
      if (CONCAT31(extraout_var_49,bVar3) == 0) {
        return false;
      }
      do {
        bVar3 = RwReadStream((int *)ppppuVar2,(undefined4 *)&stack0xfffffffc,4);
        if (CONCAT31(extraout_var_50,bVar3) == 0) break;
        ppuVar16 = (uint **)(((uint)ppuVar16 & 0xff00 | (int)ppuVar16 << 0x10) << 8 |
                            ((uint)ppuVar16 & 0xff0000 | (uint)ppuVar16 >> 0x10) >> 8);
        if (ppuVar16 == (uint **)0x504c5354) {
          bVar3 = true;
          goto LAB_1003b8fa;
        }
        iVar5 = RwSkipStreamChunk((int *)ppppuVar2);
      } while (iVar5 != 0);
      bVar3 = false;
LAB_1003b8fa:
      if (!bVar3) {
        FUN_1000cba0(0x5a);
        return false;
      }
      bVar3 = RwReadStreamChunk(ppppuVar2,0x504c5354,piVar7);
      if (CONCAT31(extraout_var_51,bVar3) == 0) {
        return false;
      }
      if (param_16 != (uint **)0x0) {
        ppuVar16 = (uint **)0x0;
LAB_1003b94a:
        do {
          bVar3 = RwReadStream((int *)ppppuVar2,(undefined4 *)&stack0xfffffff4,4);
          if (CONCAT31(extraout_var_52,bVar3) == 0) {
LAB_1003b9a3:
            bVar3 = false;
          }
          else {
            unaff_EDI = (undefined4 *)
                        (((uint)unaff_EDI & 0xff00 | (int)unaff_EDI << 0x10) << 8 |
                        ((uint)unaff_EDI & 0xff0000 | (uint)unaff_EDI >> 0x10) >> 8);
            if (unaff_EDI != (undefined4 *)0x41544f4d) {
              iVar5 = RwSkipStreamChunk((int *)ppppuVar2);
              if (iVar5 == 0) goto LAB_1003b9a3;
              goto LAB_1003b94a;
            }
            bVar3 = true;
          }
          if (!bVar3) {
            FUN_1000cba0(0x5a);
            return false;
          }
          bVar3 = RwReadStreamChunk(ppppuVar2,0x41544f4d,(int *)&stack0xfffffff8);
          if (CONCAT31(extraout_var_53,bVar3) == 0) {
            return false;
          }
          ppuVar16 = (uint **)((int)ppuVar16 + 1);
          RwAddChildToClump((int)piVar7,(uint)unaff_EDI);
        } while (ppuVar16 < param_15);
      }
      RwSetClumpHints((int)piVar7,uVar15);
      piVar7[0x32] = 0;
      piVar7[0x31] = 0;
      *param_33 = piVar7;
      return true;
    }
  }
  else if ((int)param_37 < 0x44415442) {
    if (param_37 == (uint *)0x44415441) {
      param_38[1] = uVar15;
      puVar6 = (undefined4 *)(**(code **)(PTR_DAT_1005b69c + 0x34c))(uVar15);
      *param_38 = puVar6;
      if (puVar6 == (undefined4 *)0x0) {
        FUN_1000cba0(3);
        return false;
      }
      bVar3 = RwReadStream((int *)ppppuVar2,puVar6,param_6);
      if (CONCAT31(extraout_var_09,bVar3) != 0) {
        return true;
      }
      (**(code **)(PTR_DAT_1005b69c + 0x358))(*param_38);
      return false;
    }
    if (param_37 == (uint *)0x434c554d) {
      DAT_1005b798 = FUN_10037030(DAT_1005b794);
      if (DAT_1005b798 != (int *)0x0) {
        piVar7 = FUN_10037030(DAT_1005b790);
        if (piVar7 != (int *)0x0) {
          iVar5 = (**(code **)(PTR_DAT_1005b69c + 0x34c))(0x28);
          *piVar7 = iVar5;
          if (iVar5 == 0) {
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
          iVar5 = (**(code **)(PTR_DAT_1005b69c + 0x34c))(0x28);
          *piVar7 = iVar5;
          if (iVar5 == 0) {
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
          iVar5 = (**(code **)(PTR_DAT_1005b69c + 0x34c))(0x28);
          *piVar7 = iVar5;
          if (iVar5 == 0) {
            FUN_10039be0(piVar7);
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
          iVar5 = (**(code **)(PTR_DAT_1005b69c + 0x34c))(0x28);
          *piVar7 = iVar5;
          if (iVar5 == 0) {
            FUN_10039be0(piVar7);
            piVar7 = (int *)0x0;
          }
          else {
            piVar7[2] = 0;
            piVar7[1] = 10;
          }
        }
        DAT_1005b798[3] = (int)piVar7;
        piVar7 = FUN_10039c20();
        DAT_1005b798[4] = (int)piVar7;
        DAT_1005b798[5] = 0;
        if ((((*DAT_1005b798 != 0) && (DAT_1005b798[1] != 0)) && (DAT_1005b798[2] != 0)) &&
           ((DAT_1005b798[3] != 0 && (DAT_1005b798[4] != 0)))) {
          do {
            bVar3 = RwReadStream((int *)ppppuVar2,(undefined4 *)&stack0x00000000,4);
            if (CONCAT31(extraout_var_01,bVar3) == 0) break;
            unaff_retaddr =
                 (unaff_retaddr & 0xff00 | unaff_retaddr << 0x10) << 8 |
                 (unaff_retaddr & 0xff0000 | unaff_retaddr >> 0x10) >> 8;
            if (unaff_retaddr == 0x52414c54) {
              bVar3 = true;
              goto LAB_1003a260;
            }
            iVar5 = RwSkipStreamChunk((int *)ppppuVar2);
          } while (iVar5 != 0);
          bVar3 = false;
LAB_1003a260:
          if (bVar3) {
            bVar3 = RwReadStreamChunk(ppppuVar2,0x52414c54,(int *)ppppuVar2);
            if (CONCAT31(extraout_var_02,bVar3) == 0) {
              bVar3 = false;
            }
            else {
              do {
                bVar3 = RwReadStream((int *)ppppuVar2,(undefined4 *)&stack0xfffffffc,4);
                if (CONCAT31(extraout_var_03,bVar3) == 0) break;
                unaff_EBX = (uint *)(((uint)unaff_EBX & 0xff00 | (int)unaff_EBX << 0x10) << 8 |
                                    ((uint)unaff_EBX & 0xff0000 | (uint)unaff_EBX >> 0x10) >> 8);
                if (unaff_EBX == (uint *)0x54454c54) {
                  bVar3 = true;
                  goto LAB_1003a2f4;
                }
                iVar5 = RwSkipStreamChunk((int *)ppppuVar2);
              } while (iVar5 != 0);
              bVar3 = false;
LAB_1003a2f4:
              if (bVar3) {
                bVar3 = RwReadStreamChunk(ppppuVar2,0x54454c54,(int *)ppppuVar2);
                if (CONCAT31(extraout_var_04,bVar3) == 0) {
                  bVar3 = false;
                }
                else {
                  do {
                    bVar3 = RwReadStream((int *)ppppuVar2,(undefined4 *)&stack0xfffffff8,4);
                    if (CONCAT31(extraout_var_05,bVar3) == 0) break;
                    unaff_ESI = (int *)(((uint)unaff_ESI & 0xff00 | (int)unaff_ESI << 0x10) << 8 |
                                       ((uint)unaff_ESI & 0xff0000 | (uint)unaff_ESI >> 0x10) >> 8);
                    if (unaff_ESI == (int *)0x4d414c54) {
                      bVar3 = true;
                      goto LAB_1003a388;
                    }
                    iVar5 = RwSkipStreamChunk((int *)ppppuVar2);
                  } while (iVar5 != 0);
                  bVar3 = false;
LAB_1003a388:
                  if (bVar3) {
                    bVar4 = RwReadStreamChunk(ppppuVar2,0x4d414c54,(int *)ppppuVar2);
                    bVar3 = false;
                    if (CONCAT31(extraout_var_06,bVar4) != 0) {
                      bVar3 = true;
                      DAT_1005b798[5] = 1;
                    }
                  }
                  else {
                    FUN_1000cba0(0x5a);
                    bVar3 = false;
                  }
                }
              }
              else {
                FUN_1000cba0(0x5a);
                bVar3 = false;
              }
            }
          }
          else {
            FUN_1000cba0(0x5a);
            bVar3 = false;
          }
          if (!bVar3) {
            FUN_1003d550();
            return false;
          }
          do {
            bVar3 = RwReadStream((int *)ppppuVar2,(undefined4 *)&stack0x00000000,4);
            if (CONCAT31(extraout_var_07,bVar3) == 0) break;
            unaff_retaddr =
                 (unaff_retaddr & 0xff00 | unaff_retaddr << 0x10) << 8 |
                 (unaff_retaddr & 0xff0000 | unaff_retaddr >> 0x10) >> 8;
            if (unaff_retaddr == 0x41544f4d) {
              bVar3 = true;
              goto LAB_1003a435;
            }
            iVar5 = RwSkipStreamChunk((int *)ppppuVar2);
          } while (iVar5 != 0);
          bVar3 = false;
LAB_1003a435:
          if (!bVar3) {
            FUN_1003d550();
            FUN_1000cba0(0x5a);
            return false;
          }
          bVar3 = RwReadStreamChunk(ppppuVar2,0x41544f4d,(int *)&param_3);
          if (CONCAT31(extraout_var_08,bVar3) != 0) {
            FUN_1003d550();
            *param_37 = param_2;
            return true;
          }
          FUN_1003d550();
          return false;
        }
        FUN_1003d550();
      }
      return false;
    }
  }
  else if ((int)param_37 < 0x4d414c55) {
    if (param_37 == (uint *)0x4d414c54) {
      do {
        bVar3 = RwReadStream((int *)ppppuVar2,&param_3,4);
        if (CONCAT31(extraout_var_66,bVar3) == 0) break;
        param_3 = (param_3 & 0xff00 | param_3 << 0x10) << 8 |
                  (param_3 & 0xff0000 | param_3 >> 0x10) >> 8;
        if (param_3 == 0x53545254) {
          bVar3 = true;
          goto LAB_1003c02e;
        }
        iVar5 = RwSkipStreamChunk((int *)ppppuVar2);
      } while (iVar5 != 0);
      bVar3 = false;
LAB_1003c02e:
      if (!bVar3) {
        FUN_1000cba0(0x5a);
        return false;
      }
      bVar3 = RwReadStreamChunk(ppppuVar2,0x53545254,(int *)&param_7);
      if (CONCAT31(extraout_var_67,bVar3) == 0) {
        return false;
      }
      iVar5 = 3;
      puVar8 = &param_6;
      do {
        uVar15 = *puVar8;
        iVar5 = iVar5 + -1;
        *puVar8 = (uVar15 & 0xff00 | uVar15 << 0x10) << 8 |
                  (uVar15 & 0xff0000 | uVar15 >> 0x10) >> 8;
        puVar8 = puVar8 + 1;
      } while (iVar5 != 0);
      uVar15 = 0;
      if (param_6 == 0) {
        return true;
      }
      do {
        bVar3 = RwReadStream((int *)ppppuVar2,&param_9,0x28);
        if (CONCAT31(extraout_var_68,bVar3) == 0) {
          return false;
        }
        if (0x28 < param_7) {
          RwSeekStream((int *)ppppuVar2,param_7 - 0x28);
        }
        iVar5 = 10;
        pppuVar9 = &param_9;
        do {
          ppuVar16 = *pppuVar9;
          iVar5 = iVar5 + -1;
          *pppuVar9 = (uint **)(((uint)ppuVar16 & 0xff00 | (int)ppuVar16 << 0x10) << 8 |
                               ((uint)ppuVar16 & 0xff0000 | (uint)ppuVar16 >> 0x10) >> 8);
          pppuVar9 = pppuVar9 + 1;
        } while (iVar5 != 0);
        puVar8 = RwCreateMaterial();
        if (puVar8 == (uint *)0x0) {
          return false;
        }
        *puVar8 = (uint)param_10;
        *(undefined1 *)(puVar8 + 0xc) = param_11._0_1_;
        RwSetMaterialColor((int)puVar8,(uint)param_12,(uint)param_13,(uint)param_14);
        RwSetMaterialOpacity(puVar8,(uint)param_15);
        RwSetMaterialSurface((int)puVar8,(uint)param_16,(uint)param_17,(uint)param_18);
        if (param_9 != (uint **)0x0) {
          if (((uint **)((int *)DAT_1005b798[1])[2] < param_9) || (param_9 == (uint **)0x0)) {
            uVar10 = 0;
          }
          else {
            uVar10 = *(uint *)(*(int *)DAT_1005b798[1] + -4 + (int)param_9 * 4);
          }
          RwSetMaterialTexture(puVar8,uVar10);
        }
        piVar11 = (int *)DAT_1005b798[2];
        piVar7 = (int *)(*piVar11 + piVar11[2] * 4);
        iVar5 = piVar11[2];
        do {
          piVar7 = piVar7 + -1;
          if (iVar5 == 0) {
            uVar10 = piVar11[1];
            if (uVar10 <= (uint)piVar11[2]) {
              iVar5 = (**(code **)(PTR_DAT_1005b69c + 0x354))(*piVar11,uVar10 * 4 + 0xa0);
              if (iVar5 == 0) break;
              *piVar11 = iVar5;
              piVar11[1] = uVar10 + 0x28;
            }
            *(uint **)(*piVar11 + piVar11[2] * 4) = puVar8;
            piVar11[2] = piVar11[2] + 1;
            break;
          }
          iVar5 = iVar5 + -1;
        } while ((uint *)*piVar7 != puVar8);
        uVar15 = uVar15 + 1;
        if (param_6 <= uVar15) {
          return true;
        }
      } while( true );
    }
    if (param_37 == (uint *)0x4c495445) {
      do {
        bVar3 = RwReadStream((int *)ppppuVar2,(undefined4 *)&stack0x00000000,4);
        if (CONCAT31(extraout_var_62,bVar3) == 0) break;
        unaff_retaddr =
             (unaff_retaddr & 0xff0000 | unaff_retaddr >> 0x10) >> 8 |
             (unaff_retaddr & 0xff00 | unaff_retaddr << 0x10) << 8;
        if (unaff_retaddr == 0x53545254) {
          bVar3 = true;
          goto LAB_1003be23;
        }
        iVar5 = RwSkipStreamChunk((int *)ppppuVar2);
      } while (iVar5 != 0);
      bVar3 = false;
LAB_1003be23:
      if (!bVar3) {
        FUN_1000cba0(0x5a);
        return false;
      }
      bVar3 = RwReadStreamChunk(ppppuVar2,0x53545254,(int *)&param_10);
      if (CONCAT31(extraout_var_63,bVar3) == 0) {
        return false;
      }
      do {
        bVar3 = RwReadStream((int *)ppppuVar2,(undefined4 *)&stack0xfffffffc,4);
        if (CONCAT31(extraout_var_64,bVar3) == 0) break;
        unaff_EBX = (uint *)(((uint)unaff_EBX & 0xff00 | (int)unaff_EBX << 0x10) << 8 |
                            ((uint)unaff_EBX & 0xff0000 | (uint)unaff_EBX >> 0x10) >> 8);
        if (unaff_EBX == (uint *)0x4d415458) {
          bVar3 = true;
          goto LAB_1003beb5;
        }
        iVar5 = RwSkipStreamChunk((int *)ppppuVar2);
      } while (iVar5 != 0);
      bVar3 = false;
LAB_1003beb5:
      if (!bVar3) {
        FUN_1000cba0(0x5a);
        return false;
      }
      bVar3 = RwReadStreamChunk(ppppuVar2,0x4d415458,(int *)&param_2);
      if (CONCAT31(extraout_var_65,bVar3) != 0) {
        pppuVar9 = (uint ***)RwCreateLight(1,0.0,1.0,0.0,0.0);
        if (pppuVar9 != (uint ***)0x0) {
          ppuVar16 = param_1;
          pppuVar13 = pppuVar9 + 2;
          for (iVar5 = 0x11; iVar5 != 0; iVar5 = iVar5 + -1) {
            *pppuVar13 = (uint **)*ppuVar16;
            ppuVar16 = ppuVar16 + 1;
            pppuVar13 = pppuVar13 + 1;
          }
          iVar5 = 0xe;
          RwDestroyMatrix(param_1);
          pppuVar13 = &param_8;
          do {
            ppuVar16 = *pppuVar13;
            iVar5 = iVar5 + -1;
            *pppuVar13 = (uint **)(((uint)ppuVar16 & 0xff00 | (int)ppuVar16 << 0x10) << 8 |
                                  ((uint)ppuVar16 & 0xff0000 | (uint)ppuVar16 >> 0x10) >> 8);
            pppuVar13 = pppuVar13 + 1;
          } while (iVar5 != 0);
          pppuVar9[1] = param_8;
          pppuVar9[0x21] = param_9;
          pppuVar9[0x19] = param_10;
          pppuVar9[0x1a] = param_11;
          pppuVar9[0x1b] = param_12;
          pppuVar9[0x1c] = param_13;
          pppuVar9[0x1d] = param_14;
          pppuVar9[0x1e] = param_16;
          pppuVar9[0x1f] = param_17;
          pppuVar9[0x20] = param_18;
          pppuVar9[0x16] = param_19;
          pppuVar9[0x17] = param_20;
          pppuVar9[0x18] = param_21;
          *param_36 = pppuVar9;
          return true;
        }
        RwDestroyMatrix(param_1);
        return false;
      }
      return false;
    }
  }
  else if ((int)param_37 < 0x4d415459) {
    if (param_37 == (uint *)0x4d415458) {
      do {
        bVar3 = RwReadStream((int *)ppppuVar2,&param_3,4);
        if (CONCAT31(extraout_var_73,bVar3) == 0) break;
        param_3 = (param_3 & 0xff00 | param_3 << 0x10) << 8 |
                  (param_3 & 0xff0000 | param_3 >> 0x10) >> 8;
        if (param_3 == 0x53545254) {
          bVar3 = true;
          goto LAB_1003c448;
        }
        iVar5 = RwSkipStreamChunk((int *)ppppuVar2);
      } while (iVar5 != 0);
      bVar3 = false;
LAB_1003c448:
      if (!bVar3) {
        FUN_1000cba0(0x5a);
        return false;
      }
      bVar3 = RwReadStreamChunk(ppppuVar2,0x53545254,(int *)&param_10);
      if (CONCAT31(extraout_var_74,bVar3) != 0) {
        puVar6 = RwCreateMatrix();
        *param_37 = (uint)puVar6;
        if (puVar6 != (undefined4 *)0x0) {
          iVar5 = 0x10;
          pppuVar9 = &param_9;
          do {
            ppuVar16 = *pppuVar9;
            iVar5 = iVar5 + -1;
            *pppuVar9 = (uint **)(((uint)ppuVar16 & 0xff00 | (int)ppuVar16 << 0x10) << 8 |
                                 ((uint)ppuVar16 & 0xff0000 | (uint)ppuVar16 >> 0x10) >> 8);
            pppuVar9 = pppuVar9 + 1;
          } while (iVar5 != 0);
          RwSetMatrixElements((undefined4 *)*param_37,&param_9);
          return true;
        }
        return false;
      }
      return false;
    }
    if (param_37 == (uint *)0x4d415452) {
      do {
        bVar3 = RwReadStream((int *)ppppuVar2,(undefined4 *)&stack0x00000000,4);
        if (CONCAT31(extraout_var_69,bVar3) == 0) break;
        unaff_retaddr =
             (unaff_retaddr & 0xff00 | unaff_retaddr << 0x10) << 8 |
             (unaff_retaddr & 0xff0000 | unaff_retaddr >> 0x10) >> 8;
        if (unaff_retaddr == 0x53545254) {
          bVar3 = true;
          goto LAB_1003c26b;
        }
        iVar5 = RwSkipStreamChunk((int *)ppppuVar2);
      } while (iVar5 != 0);
      bVar3 = false;
LAB_1003c26b:
      if (!bVar3) {
        FUN_1000cba0(0x5a);
        return false;
      }
      bVar3 = RwReadStreamChunk(ppppuVar2,0x53545254,(int *)&param_10);
      if (CONCAT31(extraout_var_70,bVar3) == 0) {
        return false;
      }
      iVar5 = 10;
      pppuVar9 = &param_9;
      do {
        ppuVar16 = *pppuVar9;
        iVar5 = iVar5 + -1;
        *pppuVar9 = (uint **)(((uint)ppuVar16 & 0xff00 | (int)ppuVar16 << 0x10) << 8 |
                             ((uint)ppuVar16 & 0xff0000 | (uint)ppuVar16 >> 0x10) >> 8);
        pppuVar9 = pppuVar9 + 1;
      } while (iVar5 != 0);
      pppuVar9 = (uint ***)RwCreateMaterial();
      if (pppuVar9 == (uint ***)0x0) {
        return false;
      }
      *pppuVar9 = param_10;
      *(undefined1 *)(pppuVar9 + 0xc) = param_11._0_1_;
      RwSetMaterialColor((int)pppuVar9,(uint)param_12,(uint)param_13,(uint)param_14);
      RwSetMaterialOpacity((uint *)pppuVar9,(uint)param_15);
      ppuVar16 = param_17;
      RwSetMaterialSurface((int)pppuVar9,(uint)param_16,(uint)param_17,(uint)param_18);
      if (param_9 != (uint **)0x0) {
        do {
          bVar3 = RwReadStream((int *)ppppuVar2,(undefined4 *)&stack0xfffffffc,4);
          if (CONCAT31(extraout_var_71,bVar3) == 0) break;
          unaff_EBX = (uint *)(((int)unaff_EBX << 0x10 | (uint)unaff_EBX & 0xff00) << 8 |
                              ((uint)unaff_EBX >> 0x10 | (uint)unaff_EBX & 0xff0000) >> 8);
          if (unaff_EBX == (uint *)0x54455855) {
            bVar3 = true;
            goto LAB_1003c397;
          }
          iVar5 = RwSkipStreamChunk((int *)ppppuVar2);
        } while (iVar5 != 0);
        bVar3 = false;
LAB_1003c397:
        if (!bVar3) {
          FUN_1000cba0(0x5a);
          return false;
        }
        bVar3 = RwReadStreamChunk(ppppuVar2,0x54455855,(int *)&param_2);
        ppuVar16 = param_1;
        if (CONCAT31(extraout_var_72,bVar3) == 0) {
          return false;
        }
      }
      RwSetMaterialTexture((uint *)pppuVar9,(uint)ppuVar16);
      *param_36 = pppuVar9;
      return true;
    }
  }
  else if ((int)param_37 < 0x504c5355) {
    if (param_37 == (uint *)0x504c5354) {
      do {
        bVar3 = RwReadStream((int *)ppppuVar2,&param_3,4);
        if (CONCAT31(extraout_var_11,bVar3) == 0) break;
        param_3 = (param_3 & 0xff00 | param_3 << 0x10) << 8 |
                  (param_3 & 0xff0000 | param_3 >> 0x10) >> 8;
        if (param_3 == 0x53545254) {
          bVar3 = true;
          goto LAB_1003a5e3;
        }
        iVar5 = RwSkipStreamChunk((int *)ppppuVar2);
      } while (iVar5 != 0);
      bVar3 = false;
LAB_1003a5e3:
      if (!bVar3) {
        FUN_1000cba0(0x5a);
        return false;
      }
      bVar3 = RwReadStreamChunk(ppppuVar2,0x53545254,(int *)&param_7);
      if (CONCAT31(extraout_var_12,bVar3) == 0) {
        return false;
      }
      iVar5 = 3;
      puVar8 = &param_6;
      do {
        uVar15 = *puVar8;
        iVar5 = iVar5 + -1;
        *puVar8 = (uVar15 & 0xff00 | uVar15 << 0x10) << 8 |
                  (uVar15 & 0xff0000 | uVar15 >> 0x10) >> 8;
        puVar8 = puVar8 + 1;
      } while (iVar5 != 0);
      puVar6 = FUN_10020b70(param_6);
      if (puVar6 == (undefined4 *)0x0) {
        return false;
      }
      FUN_10020be0((undefined4 *)param_37[0x26]);
      param_37[0x26] = (uint)puVar6;
      iVar5 = (((uint)param_8 & 0x10) >> 2) + (((int)param_8 << 0x1d) >> 0x1f & 0xcU) + 8 +
              (((int)param_8 << 0x1f) >> 0x1f & 0xcU);
      if (iVar5 < (int)param_7) {
        param_2 = param_7 - iVar5;
      }
      else {
        param_2 = 0;
      }
      uVar15 = 0;
      if (param_6 == 0) {
        return true;
      }
      while( true ) {
        bVar3 = RwReadStream((int *)ppppuVar2,&param_9,8);
        if (CONCAT31(extraout_var_13,bVar3) == 0) {
          return false;
        }
        iVar5 = 2;
        pppuVar9 = &param_9;
        do {
          ppuVar16 = *pppuVar9;
          iVar5 = iVar5 + -1;
          *pppuVar9 = (uint **)(((uint)ppuVar16 & 0xff00 | (int)ppuVar16 << 0x10) << 8 |
                               ((uint)ppuVar16 & 0xff0000 | (uint)ppuVar16 >> 0x10) >> 8);
          pppuVar9 = pppuVar9 + 1;
        } while (iVar5 != 0);
        bVar3 = RwReadStream((int *)ppppuVar2,&DAT_1005e070,(int)param_10 << 2);
        if (CONCAT31(extraout_var_14,bVar3) == 0) {
          return false;
        }
        puVar8 = &DAT_1005e070;
        for (uVar10 = (uint)param_10 & 0x3fffffff; uVar10 != 0; uVar10 = uVar10 - 1) {
          uVar1 = *puVar8;
          *puVar8 = (uVar1 & 0xff00 | uVar1 << 0x10) << 8 | (uVar1 & 0xff0000 | uVar1 >> 0x10) >> 8;
          puVar8 = puVar8 + 1;
        }
        puVar6 = FUN_10001220((int)param_10,param_37[0x22],&DAT_1005e070);
        if (puVar6 == (undefined4 *)0x0) {
          return false;
        }
        bVar3 = FUN_10003660((uint)param_37,puVar6);
        if (CONCAT31(extraout_var_15,bVar3) == 0) {
          return false;
        }
        if (((uint **)((int *)DAT_1005b798[2])[2] < param_9) || (param_9 == (uint **)0x0)) {
          piVar7 = (int *)0x0;
        }
        else {
          piVar7 = *(int **)(*(int *)DAT_1005b798[2] + -4 + (int)param_9 * 4);
        }
        RwSetPolygonMaterial(puVar6,piVar7);
        if (((uint)param_8 & 1) != 0) {
          bVar3 = RwReadStream((int *)ppppuVar2,&param_9,0xc);
          if (CONCAT31(extraout_var_16,bVar3) == 0) {
            return false;
          }
          iVar5 = 3;
          pppuVar9 = &param_9;
          do {
            ppuVar16 = *pppuVar9;
            iVar5 = iVar5 + -1;
            *pppuVar9 = (uint **)(((uint)ppuVar16 & 0xff00 | (int)ppuVar16 << 0x10) << 8 |
                                 ((uint)ppuVar16 & 0xff0000 | (uint)ppuVar16 >> 0x10) >> 8);
            pppuVar9 = pppuVar9 + 1;
          } while (iVar5 != 0);
          puVar6[4] = param_9;
          puVar6[5] = param_10;
          puVar6[6] = param_11;
        }
        if (((uint)param_8 & 4) != 0) {
          bVar3 = RwReadStream((int *)ppppuVar2,&param_9,0xc);
          if (CONCAT31(extraout_var_17,bVar3) == 0) {
            return false;
          }
          iVar5 = 3;
          pppuVar9 = &param_9;
          do {
            ppuVar16 = *pppuVar9;
            iVar5 = iVar5 + -1;
            *pppuVar9 = (uint **)(((uint)ppuVar16 & 0xff00 | (int)ppuVar16 << 0x10) << 8 |
                                 ((uint)ppuVar16 & 0xff0000 | (uint)ppuVar16 >> 0x10) >> 8);
            pppuVar9 = pppuVar9 + 1;
          } while (iVar5 != 0);
          lVar23 = __ftol();
          puVar6[1] = (int)lVar23;
          lVar23 = __ftol();
          puVar6[2] = (int)lVar23;
          lVar23 = __ftol();
          puVar6[3] = (int)lVar23;
        }
        if (((uint)param_8 & 0x10) != 0) {
          bVar3 = RwReadStream((int *)ppppuVar2,&param_9,4);
          if (CONCAT31(extraout_var_18,bVar3) == 0) {
            return false;
          }
          iVar5 = 1;
          pppuVar9 = &param_9;
          do {
            ppuVar16 = *pppuVar9;
            iVar5 = iVar5 + -1;
            *pppuVar9 = (uint **)(((uint)ppuVar16 & 0xff00 | (int)ppuVar16 << 0x10) << 8 |
                                 ((uint)ppuVar16 & 0xff0000 | (uint)ppuVar16 >> 0x10) >> 8);
            pppuVar9 = pppuVar9 + 1;
          } while (iVar5 != 0);
          *(short *)(puVar6 + 0xe) = (short)param_9;
        }
        if ((param_2 != 0) && (iVar5 = RwSeekStream((int *)ppppuVar2,param_2), iVar5 == 0)) break;
        uVar15 = uVar15 + 1;
        if (param_6 <= uVar15) {
          return true;
        }
      }
      return false;
    }
    if (param_37 == (uint *)0x50414c4c) {
      iVar5 = 0;
      puVar6 = param_38;
      do {
        bVar3 = RwReadStream((int *)ppppuVar2,&param_3,param_6 >> 8);
        if (CONCAT31(extraout_var_10,bVar3) == 0) {
          return false;
        }
        if (param_6 < 0x400) {
          RwSeekStream((int *)ppppuVar2,4 - (param_6 >> 8));
        }
        iVar5 = iVar5 + 1;
        *(undefined1 *)puVar6 = (undefined1)param_3;
        *(undefined1 *)((int)puVar6 + 1) = param_3._1_1_;
        *(undefined1 *)((int)puVar6 + 2) = param_3._2_1_;
        puVar6 = puVar6 + 1;
      } while (iVar5 < 0x100);
      return true;
    }
  }
  else if ((int)param_37 < 0x52415355) {
    if (param_37 == (uint *)0x52415354) {
      do {
        bVar3 = RwReadStream((int *)ppppuVar2,&param_3,4);
        if (CONCAT31(extraout_var_79,bVar3) == 0) break;
        param_3 = (param_3 & 0xff00 | param_3 << 0x10) << 8 |
                  (param_3 & 0xff0000 | param_3 >> 0x10) >> 8;
        if (param_3 == 0x53545254) {
          bVar3 = true;
          goto LAB_1003c78a;
        }
        iVar5 = RwSkipStreamChunk((int *)ppppuVar2);
      } while (iVar5 != 0);
      bVar3 = false;
LAB_1003c78a:
      if (!bVar3) {
        FUN_1000cba0(0x5a);
        return false;
      }
      bVar3 = RwReadStreamChunk(ppppuVar2,0x53545254,(int *)&param_10);
      if (CONCAT31(extraout_var_80,bVar3) == 0) {
        return false;
      }
      iVar5 = 10;
      pppuVar9 = &param_9;
      do {
        ppuVar16 = *pppuVar9;
        iVar5 = iVar5 + -1;
        *pppuVar9 = (uint **)(((uint)ppuVar16 & 0xff00 | (int)ppuVar16 << 0x10) << 8 |
                             ((uint)ppuVar16 & 0xff0000 | (uint)ppuVar16 >> 0x10) >> 8);
        pppuVar9 = pppuVar9 + 1;
      } while (iVar5 != 0);
      do {
        bVar3 = RwReadStream((int *)ppppuVar2,&param_2,4);
        if (CONCAT31(extraout_var_81,bVar3) == 0) break;
        param_2 = (param_2 & 0xff00 | param_2 << 0x10) << 8 |
                  (param_2 & 0xff0000 | param_2 >> 0x10) >> 8;
        if (param_2 == 0x44415441) {
          bVar3 = true;
          goto LAB_1003c853;
        }
        iVar5 = RwSkipStreamChunk((int *)ppppuVar2);
      } while (iVar5 != 0);
      bVar3 = false;
LAB_1003c853:
      if (!bVar3) {
        FUN_1000cba0(0x5a);
        return false;
      }
      uVar24 = 0;
      bVar3 = RwReadStreamChunk(ppppuVar2,0x44415441,&param_32);
      piVar7 = param_31;
      if (CONCAT31(extraout_var_82,bVar3) == 0) {
        return false;
      }
      pppuVar9 = (uint ***)RwCreateRaster(param_8,param_9);
      if (pppuVar9 != (uint ***)0x0) {
        if (((*pppuVar9 == param_12) && (pppuVar9[1] == param_13)) &&
           ((pppuVar9[2] == param_14 &&
            (((pppuVar9[3] == param_15 && (pppuVar9[4] == param_16)) && (pppuVar9[5] == param_17))))
           )) {
          ppuVar16 = (uint **)RwGetRasterStride((int)pppuVar9);
          if (ppuVar16 < param_11) {
            ppuVar16 = param_11;
          }
          param_1 = (uint **)RwGetRasterPixels((int)pppuVar9);
          ppuVar19 = param_9;
          ppuVar14 = param_1;
          if (0 < (int)param_9) {
            do {
              piVar11 = piVar7;
              ppuVar22 = ppuVar14;
              for (uVar15 = (uint)ppuVar16 >> 2; uVar15 != 0; uVar15 = uVar15 - 1) {
                *ppuVar22 = (uint *)*piVar11;
                piVar11 = piVar11 + 1;
                ppuVar22 = ppuVar22 + 1;
              }
              for (uVar15 = (uint)ppuVar16 & 3; uVar15 != 0; uVar15 = uVar15 - 1) {
                *(char *)ppuVar22 = (char)*piVar11;
                piVar11 = (int *)((int)piVar11 + 1);
                ppuVar22 = (uint **)((int)ppuVar22 + 1);
              }
              iVar5 = RwGetRasterStride((int)pppuVar9);
              ppuVar14 = (uint **)((int)ppuVar14 + iVar5);
              piVar7 = (int *)((int)piVar7 + (int)param_11);
              ppuVar19 = (uint **)((int)ppuVar19 + -1);
            } while (ppuVar19 != (uint **)0x0);
          }
          RwReleaseRasterPixels((int)pppuVar9);
          goto LAB_1003ca0d;
        }
        puVar6 = FUN_10021050(0,0,0);
        if (puVar6 != (undefined4 *)0x0) {
          puVar6[7] = param_8;
          puVar6[8] = param_9;
          puVar6[9] = param_10;
          puVar6[10] = param_11;
          *puVar6 = param_12;
          puVar6[1] = param_13;
          puVar6[2] = param_14;
          puVar6[3] = param_15;
          puVar6[4] = param_16;
          puVar6[5] = param_17;
          puVar6[6] = piVar7;
          iVar5 = (**(code **)(PTR_DAT_1005b69c + 0x48))(puVar6,pppuVar9,8,uVar24);
          puVar6[6] = 0;
          RwDestroyRaster(puVar6);
          if (iVar5 != 0) goto LAB_1003ca0d;
          RwDestroyRaster(pppuVar9);
        }
      }
      pppuVar9 = (uint ***)0x0;
LAB_1003ca0d:
      if (pppuVar9 != (uint ***)0x0) {
        (**(code **)(PTR_DAT_1005b69c + 0x358))(param_31);
        *param_36 = pppuVar9;
        return true;
      }
      (**(code **)(PTR_DAT_1005b69c + 0x358))();
      return false;
    }
    if (param_37 == (uint *)0x52414c54) {
      do {
        bVar3 = RwReadStream((int *)ppppuVar2,&param_3,4);
        if (CONCAT31(extraout_var_75,bVar3) == 0) break;
        param_3 = (param_3 & 0xff00 | param_3 << 0x10) << 8 |
                  (param_3 & 0xff0000 | param_3 >> 0x10) >> 8;
        if (param_3 == 0x53545254) {
          bVar3 = true;
          goto LAB_1003c543;
        }
        iVar5 = RwSkipStreamChunk((int *)ppppuVar2);
      } while (iVar5 != 0);
      bVar3 = false;
LAB_1003c543:
      if (!bVar3) {
        FUN_1000cba0(0x5a);
        return false;
      }
      bVar3 = RwReadStreamChunk(ppppuVar2,0x53545254,(int *)&param_7);
      if (CONCAT31(extraout_var_76,bVar3) == 0) {
        return false;
      }
      iVar5 = 3;
      puVar8 = &param_6;
      do {
        uVar15 = *puVar8;
        iVar5 = iVar5 + -1;
        *puVar8 = (uVar15 & 0xff00 | uVar15 << 0x10) << 8 |
                  (uVar15 & 0xff0000 | uVar15 >> 0x10) >> 8;
        puVar8 = puVar8 + 1;
      } while (iVar5 != 0);
      uVar15 = 0;
LAB_1003c5ae:
      do {
        if ((int)param_6 <= (int)uVar15) {
          return true;
        }
        do {
          bVar3 = RwReadStream((int *)ppppuVar2,&param_1,4);
          if (CONCAT31(extraout_var_77,bVar3) == 0) break;
          param_1 = (uint **)(((uint)param_1 & 0xff00 | (int)param_1 << 0x10) << 8 |
                             ((uint)param_1 & 0xff0000 | (uint)param_1 >> 0x10) >> 8);
          if (param_1 == (uint **)0x52415354) {
            bVar3 = true;
            goto LAB_1003c61a;
          }
          iVar5 = RwSkipStreamChunk((int *)ppppuVar2);
        } while (iVar5 != 0);
        bVar3 = false;
LAB_1003c61a:
        if (!bVar3) {
          while (uVar10 = uVar15 - 1, -1 < (int)uVar10) {
            if ((param_37[2] < uVar15) || (uVar10 == 0xffffffff)) {
              puVar6 = (undefined4 *)0x0;
            }
            else {
              puVar6 = *(undefined4 **)(*param_37 + uVar10 * 4);
            }
            RwDestroyRaster(puVar6);
            uVar15 = uVar10;
          }
          FUN_1000cba0(0x5a);
          return false;
        }
        puVar6 = param_38;
        bVar3 = RwReadStreamChunk(ppppuVar2,0x52415354,(int *)&stack0x00000000);
        if (CONCAT31(extraout_var_78,bVar3) == 0) {
          while (uVar10 = uVar15 - 1, -1 < (int)uVar10) {
            if (((uint)((int *)*DAT_1005b798)[2] < uVar15) || (uVar10 == 0xffffffff)) {
              puVar6 = (undefined4 *)0x0;
            }
            else {
              puVar6 = *(undefined4 **)(*(int *)*DAT_1005b798 + uVar10 * 4);
            }
            RwDestroyRaster(puVar6);
            uVar15 = uVar10;
          }
          return false;
        }
        piVar7 = (int *)*DAT_1005b798;
        param_1 = (uint **)*piVar7;
        ppuVar16 = param_1 + piVar7[2];
        iVar5 = piVar7[2];
        do {
          ppuVar16 = ppuVar16 + -1;
          if (iVar5 == 0) {
            uVar10 = piVar7[1];
            if ((uint)piVar7[2] < uVar10) {
LAB_1003c6a9:
              *(uint **)(*piVar7 + piVar7[2] * 4) = unaff_EBX;
              piVar7[2] = piVar7[2] + 1;
            }
            else {
              iVar5 = (**(code **)(PTR_DAT_1005b69c + 0x354))(param_1,uVar10 * 4 + 0xa0,puVar6);
              if (iVar5 != 0) {
                *piVar7 = iVar5;
                piVar7[1] = uVar10 + 0x28;
                goto LAB_1003c6a9;
              }
            }
            uVar15 = uVar15 + 1;
            goto LAB_1003c5ae;
          }
          iVar5 = iVar5 + -1;
        } while (*ppuVar16 != unaff_EBX);
        uVar15 = uVar15 + 1;
      } while( true );
    }
  }
  else if ((int)param_37 < 0x5343454f) {
    if (param_37 == (uint *)0x5343454e) {
      pppuVar9 = (uint ***)RwCreateScene();
      if (pppuVar9 == (uint ***)0x0) {
        return false;
      }
      DAT_1005b798 = FUN_10037030(DAT_1005b794);
      if (DAT_1005b798 != (int *)0x0) {
        piVar7 = FUN_10037030(DAT_1005b790);
        if (piVar7 != (int *)0x0) {
          iVar5 = (**(code **)(PTR_DAT_1005b69c + 0x34c))(0x28);
          *piVar7 = iVar5;
          if (iVar5 == 0) {
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
          iVar5 = (**(code **)(PTR_DAT_1005b69c + 0x34c))(0x28);
          *piVar7 = iVar5;
          if (iVar5 == 0) {
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
          iVar5 = (**(code **)(PTR_DAT_1005b69c + 0x34c))(0x28);
          *piVar7 = iVar5;
          if (iVar5 == 0) {
            FUN_10039be0(piVar7);
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
          iVar5 = (**(code **)(PTR_DAT_1005b69c + 0x34c))(0x28);
          *piVar7 = iVar5;
          if (iVar5 == 0) {
            FUN_10039be0(piVar7);
            piVar7 = (int *)0x0;
          }
          else {
            piVar7[2] = 0;
            piVar7[1] = 10;
          }
        }
        DAT_1005b798[3] = (int)piVar7;
        piVar7 = FUN_10039c20();
        DAT_1005b798[4] = (int)piVar7;
        DAT_1005b798[5] = 0;
        if ((((*DAT_1005b798 != 0) && (DAT_1005b798[1] != 0)) && (DAT_1005b798[2] != 0)) &&
           ((DAT_1005b798[3] != 0 && (DAT_1005b798[4] != 0)))) {
          do {
            bVar3 = RwReadStream((int *)ppppuVar2,&param_1,4);
            if (CONCAT31(extraout_var_19,bVar3) == 0) break;
            param_1 = (uint **)(((uint)param_1 & 0xff00 | (int)param_1 << 0x10) << 8 |
                               ((uint)param_1 & 0xff0000 | (uint)param_1 >> 0x10) >> 8);
            if (param_1 == (uint **)0x52414c54) {
              bVar3 = true;
              goto LAB_1003abd7;
            }
            iVar5 = RwSkipStreamChunk((int *)ppppuVar2);
          } while (iVar5 != 0);
          bVar3 = false;
LAB_1003abd7:
          if (bVar3) {
            bVar3 = RwReadStreamChunk(ppppuVar2,0x52414c54,(int *)ppppuVar2);
            if (CONCAT31(extraout_var_20,bVar3) == 0) {
              bVar3 = false;
            }
            else {
              do {
                bVar3 = RwReadStream((int *)ppppuVar2,(undefined4 *)&stack0x00000000,4);
                if (CONCAT31(extraout_var_21,bVar3) == 0) break;
                unaff_retaddr =
                     (unaff_retaddr << 0x10 | unaff_retaddr & 0xff00) << 8 |
                     (unaff_retaddr >> 0x10 | unaff_retaddr & 0xff0000) >> 8;
                if (unaff_retaddr == 0x54454c54) {
                  bVar3 = true;
                  goto LAB_1003ac6b;
                }
                iVar5 = RwSkipStreamChunk((int *)ppppuVar2);
              } while (iVar5 != 0);
              bVar3 = false;
LAB_1003ac6b:
              if (bVar3) {
                bVar3 = RwReadStreamChunk(ppppuVar2,0x54454c54,(int *)ppppuVar2);
                if (CONCAT31(extraout_var_22,bVar3) == 0) {
                  bVar3 = false;
                }
                else {
                  do {
                    bVar3 = RwReadStream((int *)ppppuVar2,(undefined4 *)&stack0xfffffffc,4);
                    if (CONCAT31(extraout_var_23,bVar3) == 0) break;
                    unaff_EBX = (uint *)(((uint)unaff_EBX & 0xff00 | (int)unaff_EBX << 0x10) << 8 |
                                        ((uint)unaff_EBX & 0xff0000 | (uint)unaff_EBX >> 0x10) >> 8)
                    ;
                    if (unaff_EBX == (uint *)0x4d414c54) {
                      bVar3 = true;
                      goto LAB_1003ad64;
                    }
                    bVar3 = RwReadStream((int *)ppppuVar2,(undefined4 *)&stack0x00000000,4);
                    if (CONCAT31(extraout_var_24,bVar3) == 0) {
LAB_1003ad4f:
                      bVar3 = false;
                    }
                    else {
                      unaff_retaddr =
                           (unaff_retaddr & 0xff00 | unaff_retaddr << 0x10) << 8 |
                           (unaff_retaddr & 0xff0000 | unaff_retaddr >> 0x10) >> 8;
                      if (unaff_retaddr == 0) {
                        bVar3 = true;
                      }
                      else {
                        iVar5 = RwSeekStream((int *)ppppuVar2,unaff_retaddr);
                        bVar3 = true;
                        if (iVar5 == 0) goto LAB_1003ad4f;
                      }
                    }
                  } while (bVar3);
                  bVar3 = false;
LAB_1003ad64:
                  if (bVar3) {
                    bVar4 = RwReadStreamChunk(ppppuVar2,0x4d414c54,(int *)ppppuVar2);
                    bVar3 = false;
                    if (CONCAT31(extraout_var_25,bVar4) != 0) {
                      bVar3 = true;
                      DAT_1005b798[5] = 1;
                    }
                  }
                  else {
                    FUN_1000cba0(0x5a);
                    bVar3 = false;
                  }
                }
              }
              else {
                FUN_1000cba0(0x5a);
                bVar3 = false;
              }
            }
          }
          else {
            FUN_1000cba0(0x5a);
            bVar3 = false;
          }
          if (!bVar3) {
            FUN_1003d550();
            return false;
          }
          do {
            bVar3 = RwReadStream((int *)ppppuVar2,&param_1,4);
            if (CONCAT31(extraout_var_26,bVar3) == 0) break;
            param_1 = (uint **)(((uint)param_1 & 0xff00 | (int)param_1 << 0x10) << 8 |
                               ((uint)param_1 & 0xff0000 | (uint)param_1 >> 0x10) >> 8);
            if (param_1 == (uint **)0x53545254) {
              bVar3 = true;
              goto LAB_1003ae11;
            }
            iVar5 = RwSkipStreamChunk((int *)ppppuVar2);
          } while (iVar5 != 0);
          bVar3 = false;
LAB_1003ae11:
          if (!bVar3) {
            FUN_1003d550();
            FUN_1000cba0(0x5a);
            return false;
          }
          bVar3 = RwReadStreamChunk(ppppuVar2,0x53545254,(int *)&param_6);
          if (CONCAT31(extraout_var_27,bVar3) == 0) {
            return false;
          }
          iVar5 = 1;
          puVar8 = &param_5;
          do {
            uVar15 = *puVar8;
            iVar5 = iVar5 + -1;
            *puVar8 = (uVar15 & 0xff00 | uVar15 << 0x10) << 8 |
                      (uVar15 & 0xff0000 | uVar15 >> 0x10) >> 8;
            puVar8 = puVar8 + 1;
          } while (iVar5 != 0);
          uVar15 = 0;
          if (param_5 != 0) {
LAB_1003ae93:
            do {
              bVar3 = RwReadStream((int *)ppppuVar2,(undefined4 *)&stack0x00000000,4);
              if (CONCAT31(extraout_var_28,bVar3) == 0) {
LAB_1003aeec:
                bVar3 = false;
              }
              else {
                unaff_retaddr =
                     (unaff_retaddr & 0xff00 | unaff_retaddr << 0x10) << 8 |
                     (unaff_retaddr & 0xff0000 | unaff_retaddr >> 0x10) >> 8;
                if (unaff_retaddr != 0x4c495445) {
                  iVar5 = RwSkipStreamChunk((int *)ppppuVar2);
                  if (iVar5 == 0) goto LAB_1003aeec;
                  goto LAB_1003ae93;
                }
                bVar3 = true;
              }
              if (!bVar3) {
                FUN_1003d550();
                RwDestroyScene(pppuVar9);
                FUN_1000cba0(0x5a);
                return false;
              }
              bVar3 = RwReadStreamChunk(ppppuVar2,0x4c495445,(int *)&param_2);
              if (CONCAT31(extraout_var_29,bVar3) == 0) {
                FUN_1003d550();
                RwDestroyScene(pppuVar9);
                return false;
              }
              uVar15 = uVar15 + 1;
              RwAddLightToScene((int)pppuVar9,param_1);
            } while (uVar15 < param_4);
          }
          do {
            bVar3 = RwReadStream((int *)ppppuVar2,(undefined4 *)&stack0x00000000,4);
            if (CONCAT31(extraout_var_30,bVar3) == 0) break;
            unaff_retaddr =
                 (unaff_retaddr & 0xff00 | unaff_retaddr << 0x10) << 8 |
                 (unaff_retaddr & 0xff0000 | unaff_retaddr >> 0x10) >> 8;
            if (unaff_retaddr == 0x53545254) {
              bVar3 = true;
              goto LAB_1003afb6;
            }
            iVar5 = RwSkipStreamChunk((int *)ppppuVar2);
          } while (iVar5 != 0);
          bVar3 = false;
LAB_1003afb6:
          if (!bVar3) {
            FUN_1003d550();
            FUN_1000cba0(0x5a);
            return false;
          }
          bVar3 = RwReadStreamChunk(ppppuVar2,0x53545254,(int *)&param_5);
          if (CONCAT31(extraout_var_31,bVar3) == 0) {
            return false;
          }
          iVar5 = 1;
          puVar8 = &param_4;
          do {
            uVar15 = *puVar8;
            iVar5 = iVar5 + -1;
            *puVar8 = (uVar15 & 0xff00 | uVar15 << 0x10) << 8 |
                      (uVar15 & 0xff0000 | uVar15 >> 0x10) >> 8;
            puVar8 = puVar8 + 1;
          } while (iVar5 != 0);
          uVar15 = 0;
          do {
            if (param_4 <= uVar15) {
              FUN_1003d550();
              *param_36 = pppuVar9;
              return true;
            }
            do {
              bVar3 = RwReadStream((int *)ppppuVar2,(undefined4 *)&stack0xfffffffc,4);
              if (CONCAT31(extraout_var_32,bVar3) == 0) break;
              unaff_EBX = (uint *)(((uint)unaff_EBX & 0xff0000 | (uint)unaff_EBX >> 0x10) >> 8 |
                                  ((uint)unaff_EBX & 0xff00 | (int)unaff_EBX << 0x10) << 8);
              if (unaff_EBX == (uint *)0x41544f4d) {
                bVar3 = true;
                goto LAB_1003b093;
              }
              iVar5 = RwSkipStreamChunk((int *)ppppuVar2);
            } while (iVar5 != 0);
            bVar3 = false;
LAB_1003b093:
            if (!bVar3) {
              FUN_1003d550();
              RwDestroyScene(pppuVar9);
              FUN_1000cba0(0x5a);
              return false;
            }
            bVar3 = RwReadStreamChunk(ppppuVar2,0x41544f4d,(int *)&stack0xfffffff8);
            if (CONCAT31(extraout_var_33,bVar3) == 0) {
              FUN_1003d550();
              RwDestroyScene(pppuVar9);
              return false;
            }
            uVar15 = uVar15 + 1;
            RwAddClumpToScene((uint)pppuVar9,(uint)unaff_EDI);
          } while( true );
        }
        FUN_1003d550();
      }
      return false;
    }
    if (param_37 == (uint *)0x52454354) {
      do {
        bVar3 = RwReadStream((int *)ppppuVar2,&param_3,4);
        if (CONCAT31(extraout_var_83,bVar3) == 0) break;
        param_3 = (param_3 & 0xff00 | param_3 << 0x10) << 8 |
                  (param_3 & 0xff0000 | param_3 >> 0x10) >> 8;
        if (param_3 == 0x53545254) {
          bVar3 = true;
          goto LAB_1003caac;
        }
        iVar5 = RwSkipStreamChunk((int *)ppppuVar2);
      } while (iVar5 != 0);
      bVar3 = false;
LAB_1003caac:
      if (!bVar3) {
        FUN_1000cba0(0x5a);
        return false;
      }
      bVar3 = RwReadStreamChunk(ppppuVar2,0x53545254,(int *)&param_10);
      if (CONCAT31(extraout_var_84,bVar3) != 0) {
        iVar5 = 4;
        pppuVar9 = &param_9;
        do {
          ppuVar16 = *pppuVar9;
          iVar5 = iVar5 + -1;
          *pppuVar9 = (uint **)(((uint)ppuVar16 & 0xff00 | (int)ppuVar16 << 0x10) << 8 |
                               ((uint)ppuVar16 & 0xff0000 | (uint)ppuVar16 >> 0x10) >> 8);
          pppuVar9 = pppuVar9 + 1;
        } while (iVar5 != 0);
        *param_37 = (uint)param_9;
        param_37[1] = (uint)param_10;
        param_37[2] = (uint)param_11;
        param_37[3] = (uint)param_12;
        return true;
      }
      return false;
    }
  }
  else if ((int)param_37 < 0x53545255) {
    if (param_37 == (uint *)0x53545254) {
      uVar10 = param_39;
      if (uVar15 <= param_39) {
        uVar10 = uVar15;
      }
      bVar3 = RwReadStream((int *)ppppuVar2,param_38,uVar10);
      if (CONCAT31(extraout_var_35,bVar3) != 0) {
        iVar5 = RwSeekStream((int *)ppppuVar2,uVar15 - param_39);
        return (bool)('\x01' - (iVar5 == 0));
      }
      return false;
    }
    if (param_37 == (uint *)0x53544e47) {
      if (uVar15 == 0) {
        *param_38 = 0;
        return true;
      }
      puVar6 = (undefined4 *)(**(code **)(PTR_DAT_1005b69c + 0x34c))(uVar15);
      *param_38 = puVar6;
      if (puVar6 != (undefined4 *)0x0) {
        bVar3 = RwReadStream((int *)ppppuVar2,puVar6,param_6);
        if (CONCAT31(extraout_var_34,bVar3) != 0) {
          return true;
        }
        return false;
      }
      FUN_1000cba0(3);
      return false;
    }
  }
  else if ((int)param_37 < 0x54455856) {
    if (param_37 == (uint *)0x54455855) {
      do {
        bVar3 = RwReadStream((int *)ppppuVar2,&param_3,4);
        if (CONCAT31(extraout_var_90,bVar3) == 0) break;
        param_3 = (param_3 & 0xff00 | param_3 << 0x10) << 8 |
                  (param_3 & 0xff0000 | param_3 >> 0x10) >> 8;
        if (param_3 == 0x53545254) {
          bVar3 = true;
          goto LAB_1003cf7c;
        }
        iVar5 = RwSkipStreamChunk((int *)ppppuVar2);
      } while (iVar5 != 0);
      bVar3 = false;
LAB_1003cf7c:
      if (!bVar3) {
        FUN_1000cba0(0x5a);
        return false;
      }
      bVar3 = RwReadStreamChunk(ppppuVar2,0x53545254,(int *)&param_10);
      if (CONCAT31(extraout_var_91,bVar3) == 0) {
        return false;
      }
      iVar5 = 5;
      pppuVar9 = &param_9;
      do {
        ppuVar16 = *pppuVar9;
        iVar5 = iVar5 + -1;
        *pppuVar9 = (uint **)(((uint)ppuVar16 & 0xff00 | (int)ppuVar16 << 0x10) << 8 |
                             ((uint)ppuVar16 & 0xff0000 | (uint)ppuVar16 >> 0x10) >> 8);
        pppuVar9 = pppuVar9 + 1;
      } while (iVar5 != 0);
      do {
        bVar3 = RwReadStream((int *)ppppuVar2,&param_2,4);
        if (CONCAT31(extraout_var_92,bVar3) == 0) break;
        param_2 = (param_2 & 0xff00 | param_2 << 0x10) << 8 |
                  (param_2 & 0xff0000 | param_2 >> 0x10) >> 8;
        if (param_2 == 0x53544e47) {
          bVar3 = true;
          goto LAB_1003d045;
        }
        iVar5 = RwSkipStreamChunk((int *)ppppuVar2);
      } while (iVar5 != 0);
      bVar3 = false;
LAB_1003d045:
      if (!bVar3) {
        FUN_1000cba0(0x5a);
        return false;
      }
      bVar3 = RwReadStreamChunk(ppppuVar2,0x53544e47,(int *)&param_1);
      if (CONCAT31(extraout_var_93,bVar3) == 0) {
        return false;
      }
      if (param_8 == (uint **)0x0) {
        unaff_ESI = (int *)0x0;
      }
      else {
        do {
          bVar3 = RwReadStream((int *)ppppuVar2,&param_1,4);
          if (CONCAT31(extraout_var_94,bVar3) == 0) break;
          param_1 = (uint **)(((uint)param_1 & 0xff00 | (int)param_1 << 0x10) << 8 |
                             ((uint)param_1 & 0xff0000 | (uint)param_1 >> 0x10) >> 8);
          if (param_1 == (uint **)0x52415354) {
            bVar3 = true;
            goto LAB_1003d18e;
          }
          iVar5 = RwSkipStreamChunk((int *)ppppuVar2);
        } while (iVar5 != 0);
        bVar3 = false;
LAB_1003d18e:
        if (!bVar3) {
          FUN_1000cba0(0x5a);
          return false;
        }
        bVar3 = RwReadStreamChunk(ppppuVar2,0x52415354,(int *)&stack0xfffffff8);
        if (CONCAT31(extraout_var_95,bVar3) == 0) {
          return false;
        }
      }
      if (param_8 == (uint **)0x0) {
        unaff_ESI = (int *)0x0;
      }
      else {
        do {
          bVar3 = RwReadStream((int *)ppppuVar2,(undefined4 *)&stack0x00000000,4);
          if (CONCAT31(extraout_var_96,bVar3) == 0) break;
          unaff_retaddr =
               (unaff_retaddr & 0xff00 | unaff_retaddr << 0x10) << 8 |
               (unaff_retaddr & 0xff0000 | unaff_retaddr >> 0x10) >> 8;
          if (unaff_retaddr == 0x52415354) {
            bVar3 = true;
            goto LAB_1003d224;
          }
          iVar5 = RwSkipStreamChunk((int *)ppppuVar2);
        } while (iVar5 != 0);
        bVar3 = false;
LAB_1003d224:
        if (!bVar3) {
          FUN_1000cba0(0x5a);
          return false;
        }
        bVar3 = RwReadStreamChunk(ppppuVar2,0x52415354,(int *)&stack0xfffffff8);
        if (CONCAT31(extraout_var_97,bVar3) == 0) {
          return false;
        }
      }
      if ((unaff_EBX != (uint *)0x0) && (((uint)param_36 & 8) == 0)) {
        piVar7 = (int *)FUN_100184d0((int)unaff_EBX);
        if (piVar7 == (int *)0x0) {
          puVar6 = FUN_10021270((char *)unaff_EBX);
          if (puVar6 != (undefined4 *)0x0) {
            piVar7 = RwGetNamedTexture((char *)unaff_EBX);
          }
          if (piVar7 == (int *)0x0) goto LAB_1003d25a;
        }
        if (unaff_EBX != (uint *)0x0) {
          (**(code **)(PTR_DAT_1005b69c + 0x358))(unaff_EBX);
        }
        if (unaff_EDI != (undefined4 *)0x0) {
          RwDestroyRaster(unaff_EDI);
        }
        if (unaff_ESI != (int *)0x0) {
          RwDestroyRaster(unaff_ESI);
        }
        *param_35 = (int)piVar7;
        return true;
      }
LAB_1003d25a:
      if (unaff_EDI == (undefined4 *)0x0) {
        FUN_1000cba0(0x5e);
        return false;
      }
      piVar7 = FUN_10017400();
      if (piVar7 == (int *)0x0) {
        if (unaff_EBX != (uint *)0x0) {
          (**(code **)(PTR_DAT_1005b69c + 0x358))(unaff_EBX);
        }
        if (unaff_EDI != (undefined4 *)0x0) {
          RwDestroyRaster(unaff_EDI);
        }
        if (unaff_ESI != (int *)0x0) {
          RwDestroyRaster(unaff_ESI);
        }
        return false;
      }
      iVar5 = RwSetTextureRaster((int)piVar7,(int)unaff_EDI);
      if (iVar5 == 0) {
        if (unaff_EBX != (uint *)0x0) {
          (**(code **)(PTR_DAT_1005b69c + 0x358))(unaff_EBX);
        }
        if (unaff_EDI != (undefined4 *)0x0) {
          RwDestroyRaster(unaff_EDI);
        }
        if (unaff_ESI != (int *)0x0) {
          RwDestroyRaster(unaff_ESI);
        }
        if (piVar7 != (int *)0x0) {
          RwDestroyTexture(piVar7);
        }
        return false;
      }
      if (unaff_ESI != (int *)0x0) {
        if ((*(uint *)(*(int *)(PTR_DAT_1005b69c + 0x2c4) + 0x78) & 0x400) == 0) {
          if (unaff_ESI != (int *)0x0) {
            RwDestroyRaster(unaff_ESI);
          }
        }
        else {
          iVar5 = RwSetTextureMipmapRaster((int)piVar7,(int)unaff_ESI);
          if (iVar5 == 0) {
            if (unaff_EBX != (uint *)0x0) {
              (**(code **)(PTR_DAT_1005b69c + 0x358))(unaff_EBX);
            }
            if (unaff_EDI != (undefined4 *)0x0) {
              RwDestroyRaster(unaff_EDI);
            }
            if (unaff_ESI != (int *)0x0) {
              RwDestroyRaster(unaff_ESI);
            }
            if (piVar7 != (int *)0x0) {
              RwDestroyTexture(piVar7);
            }
            return false;
          }
        }
      }
      if ((unaff_EBX != (uint *)0x0) && (iVar5 = FUN_100184d0((int)unaff_EBX), iVar5 != 0)) {
        (**(code **)(PTR_DAT_1005b69c + 0x358))(unaff_EBX);
        unaff_EBX = (uint *)0x0;
      }
      piVar11 = RwAddTextureToDict((char *)unaff_EBX,piVar7);
      if (piVar11 != (int *)0x0) {
        if (unaff_EBX != (uint *)0x0) {
          (**(code **)(PTR_DAT_1005b69c + 0x358))(unaff_EBX);
        }
        RwSetTextureFrame((int)piVar7,(int)param_10);
        RwSetTextureFrame((int)piVar7,(int)param_10);
        RwSetTextureFrameStep((int)piVar7,(int)param_11);
        *param_35 = (int)piVar7;
        return true;
      }
      if (unaff_EDI != (undefined4 *)0x0) {
        RwDestroyRaster(unaff_EDI);
      }
      if (unaff_ESI != (int *)0x0) {
        RwDestroyRaster(unaff_ESI);
      }
      if (piVar7 != (int *)0x0) {
        RwDestroyTexture(piVar7);
      }
      if (unaff_EBX != (uint *)0x0) {
        (**(code **)(PTR_DAT_1005b69c + 0x358))(unaff_EBX);
      }
      return false;
    }
    if (param_37 == (uint *)0x54454c54) {
      do {
        bVar3 = RwReadStream((int *)ppppuVar2,&param_3,4);
        if (CONCAT31(extraout_var_85,bVar3) == 0) break;
        param_3 = (param_3 & 0xff00 | param_3 << 0x10) << 8 |
                  (param_3 & 0xff0000 | param_3 >> 0x10) >> 8;
        if (param_3 == 0x53545254) {
          bVar3 = true;
          goto LAB_1003cb9f;
        }
        iVar5 = RwSkipStreamChunk((int *)ppppuVar2);
      } while (iVar5 != 0);
      bVar3 = false;
LAB_1003cb9f:
      if (!bVar3) {
        FUN_1000cba0(0x5a);
        return false;
      }
      bVar3 = RwReadStreamChunk(ppppuVar2,0x53545254,(int *)&param_7);
      if (CONCAT31(extraout_var_86,bVar3) == 0) {
        return false;
      }
      iVar5 = 3;
      puVar8 = &param_6;
      do {
        uVar15 = *puVar8;
        iVar5 = iVar5 + -1;
        *puVar8 = (uVar15 & 0xff00 | uVar15 << 0x10) << 8 |
                  (uVar15 & 0xff0000 | uVar15 >> 0x10) >> 8;
        puVar8 = puVar8 + 1;
      } while (iVar5 != 0);
      uVar15 = 0;
      if (param_6 == 0) {
        return true;
      }
      do {
        bVar3 = RwReadStream((int *)ppppuVar2,&param_9,0x14);
        if (CONCAT31(extraout_var_87,bVar3) == 0) {
          return false;
        }
        iVar5 = 5;
        pppuVar9 = &param_9;
        do {
          ppuVar16 = *pppuVar9;
          iVar5 = iVar5 + -1;
          *pppuVar9 = (uint **)(((uint)ppuVar16 & 0xff00 | (int)ppuVar16 << 0x10) << 8 |
                               ((uint)ppuVar16 & 0xff0000 | (uint)ppuVar16 >> 0x10) >> 8);
          pppuVar9 = pppuVar9 + 1;
        } while (iVar5 != 0);
        if (param_7 < 0x14) {
          RwSeekStream((int *)ppppuVar2,0x14 - param_7);
        }
        do {
          bVar3 = RwReadStream((int *)ppppuVar2,&param_2,4);
          if (CONCAT31(extraout_var_88,bVar3) == 0) break;
          param_2 = (param_2 & 0xff00 | param_2 << 0x10) << 8 |
                    (param_2 & 0xff0000 | param_2 >> 0x10) >> 8;
          if (param_2 == 0x53544e47) {
            bVar3 = true;
            goto LAB_1003cce3;
          }
          iVar5 = RwSkipStreamChunk((int *)ppppuVar2);
        } while (iVar5 != 0);
        bVar3 = false;
LAB_1003cce3:
        if (!bVar3) {
          FUN_1000cba0(0x5a);
          return false;
        }
        puVar6 = param_38;
        bVar3 = RwReadStreamChunk(ppppuVar2,0x53544e47,(int *)&stack0xfffffffc);
        if (CONCAT31(extraout_var_89,bVar3) == 0) {
          return false;
        }
        piVar7 = (int *)0x0;
        if (param_8 == (uint **)0x0) {
          if ((unaff_ESI != (int *)0x0) && (((uint)param_37 & 8) == 0)) {
            piVar7 = (int *)FUN_100184d0((int)unaff_ESI);
            if (piVar7 != (int *)0x0) goto LAB_1003ce2a;
            puVar12 = FUN_10021270((char *)unaff_ESI);
            if (puVar12 != (undefined4 *)0x0) {
              piVar7 = RwGetNamedTexture((char *)unaff_ESI);
            }
          }
          if (piVar7 == (int *)0x0) {
            if (unaff_ESI != (int *)0x0) {
              (**(code **)(PTR_DAT_1005b69c + 0x358))(unaff_ESI,puVar6);
            }
            FUN_1000cba0(0x5e);
            return false;
          }
        }
        else {
          if ((unaff_ESI != (int *)0x0) && (((uint)param_37 & 8) == 0)) {
            piVar7 = (int *)FUN_100184d0((int)unaff_ESI);
          }
          if (piVar7 == (int *)0x0) {
            piVar7 = FUN_10017400();
            if (((uint **)((int *)*DAT_1005b798)[2] < param_8) || (param_8 == (uint **)0x0)) {
              iVar5 = 0;
            }
            else {
              iVar5 = *(int *)(*(int *)*DAT_1005b798 + -4 + (int)param_8 * 4);
            }
            iVar5 = RwSetTextureRaster((int)piVar7,iVar5);
            if (iVar5 == 0) {
              RwDestroyTexture(piVar7);
              return false;
            }
            if (param_9 != (uint **)0x0) {
              if (((uint **)((int *)*DAT_1005b798)[2] < param_9) || (param_9 == (uint **)0x0)) {
                iVar5 = 0;
              }
              else {
                iVar5 = *(int *)(*(int *)*DAT_1005b798 + -4 + (int)param_9 * 4);
              }
              iVar5 = RwSetTextureMipmapRaster((int)piVar7,iVar5);
              if (iVar5 == 0) {
                RwDestroyTexture(piVar7);
                return false;
              }
            }
            iVar5 = FUN_100184d0((int)unaff_ESI);
            if (iVar5 != 0) {
              (**(code **)(PTR_DAT_1005b69c + 0x358))(unaff_ESI);
              unaff_ESI = (int *)0x0;
            }
            piVar11 = RwAddTextureToDict((char *)unaff_ESI,piVar7);
            if (piVar11 == (int *)0x0) {
              return false;
            }
          }
        }
LAB_1003ce2a:
        if (unaff_ESI != (int *)0x0) {
          (**(code **)(PTR_DAT_1005b69c + 0x358))(unaff_ESI);
        }
        piVar20 = (int *)DAT_1005b798[1];
        piVar11 = (int *)(*piVar20 + piVar20[2] * 4);
        iVar5 = piVar20[2];
        do {
          piVar11 = piVar11 + -1;
          if (iVar5 == 0) {
            uVar10 = piVar20[1];
            if (uVar10 <= (uint)piVar20[2]) {
              iVar5 = (**(code **)(PTR_DAT_1005b69c + 0x354))(*piVar20,uVar10 * 4 + 0xa0);
              if (iVar5 == 0) break;
              *piVar20 = iVar5;
              piVar20[1] = uVar10 + 0x28;
            }
            *(int **)(*piVar20 + piVar20[2] * 4) = piVar7;
            piVar20[2] = piVar20[2] + 1;
            break;
          }
          iVar5 = iVar5 + -1;
        } while ((int *)*piVar11 != piVar7);
        uVar15 = uVar15 + 1;
        if (param_6 <= uVar15) {
          return true;
        }
      } while( true );
    }
  }
  else {
    if (param_37 == (uint *)0x56334420) {
      do {
        bVar3 = RwReadStream((int *)ppppuVar2,&param_3,4);
        if (CONCAT31(extraout_var_98,bVar3) == 0) break;
        param_3 = (param_3 & 0xff00 | param_3 << 0x10) << 8 |
                  (param_3 & 0xff0000 | param_3 >> 0x10) >> 8;
        if (param_3 == 0x53545254) {
          bVar3 = true;
          goto LAB_1003d4af;
        }
        iVar5 = RwSkipStreamChunk((int *)ppppuVar2);
      } while (iVar5 != 0);
      bVar3 = false;
LAB_1003d4af:
      if (!bVar3) {
        FUN_1000cba0(0x5a);
        return false;
      }
      bVar3 = RwReadStreamChunk(ppppuVar2,0x53545254,(int *)&param_10);
      if (CONCAT31(extraout_var_99,bVar3) != 0) {
        iVar5 = 3;
        pppuVar9 = &param_9;
        do {
          ppuVar16 = *pppuVar9;
          iVar5 = iVar5 + -1;
          *pppuVar9 = (uint **)(((uint)ppuVar16 & 0xff00 | (int)ppuVar16 << 0x10) << 8 |
                               ((uint)ppuVar16 & 0xff0000 | (uint)ppuVar16 >> 0x10) >> 8);
          pppuVar9 = pppuVar9 + 1;
        } while (iVar5 != 0);
        *param_37 = (uint)param_9;
        param_37[1] = (uint)param_10;
        param_37[2] = (uint)param_11;
        return true;
      }
      return false;
    }
    if (param_37 == (uint *)0x564c5354) {
      do {
        bVar3 = RwReadStream((int *)ppppuVar2,&param_3,4);
        if (CONCAT31(extraout_var_36,bVar3) == 0) break;
        param_3 = (param_3 & 0xff00 | param_3 << 0x10) << 8 |
                  (param_3 & 0xff0000 | param_3 >> 0x10) >> 8;
        if (param_3 == 0x53545254) {
          bVar3 = true;
          goto LAB_1003b21f;
        }
        iVar5 = RwSkipStreamChunk((int *)ppppuVar2);
      } while (iVar5 != 0);
      bVar3 = false;
LAB_1003b21f:
      if (!bVar3) {
        FUN_1000cba0(0x5a);
        return false;
      }
      bVar3 = RwReadStreamChunk(ppppuVar2,0x53545254,(int *)&param_7);
      if (CONCAT31(extraout_var_37,bVar3) != 0) {
        iVar5 = 3;
        puVar8 = &param_6;
        do {
          uVar15 = *puVar8;
          iVar5 = iVar5 + -1;
          *puVar8 = (uVar15 & 0xff00 | uVar15 << 0x10) << 8 |
                    (uVar15 & 0xff0000 | uVar15 >> 0x10) >> 8;
          puVar8 = puVar8 + 1;
        } while (iVar5 != 0);
        puVar6 = FUN_10041cb0(param_6);
        if (puVar6 != (undefined4 *)0x0) {
          *(undefined4 *)param_37[0x22] = 0;
          FUN_10041d80((int *)param_37[0x22]);
          param_37[0x22] = (uint)puVar6;
          *puVar6 = param_37;
          puVar6[2] = param_6;
          iVar5 = (((int)param_8 << 0x1d) >> 0x1f & 0xcU) + ((uint)param_8 & 2) * 4 + 0xc +
                  (((int)param_8 << 0x1f) >> 0x1f & 0xcU);
          if (iVar5 < (int)param_7) {
            param_2 = param_7 - iVar5;
          }
          else {
            param_2 = 0;
          }
          uVar15 = 0;
          if (param_6 == 0) {
            return true;
          }
          pbVar17 = (byte *)(puVar6 + 0x15);
          do {
            *pbVar17 = 0;
            bVar3 = RwReadStream((int *)ppppuVar2,&param_9,0xc);
            if (CONCAT31(extraout_var_38,bVar3) == 0) {
              return false;
            }
            iVar5 = 3;
            pppuVar9 = &param_9;
            do {
              ppuVar16 = *pppuVar9;
              iVar5 = iVar5 + -1;
              *pppuVar9 = (uint **)(((uint)ppuVar16 & 0xff00 | (int)ppuVar16 << 0x10) << 8 |
                                   ((uint)ppuVar16 & 0xff0000 | (uint)ppuVar16 >> 0x10) >> 8);
              pppuVar9 = pppuVar9 + 1;
            } while (iVar5 != 0);
            *(uint ***)(pbVar17 + -0x48) = param_9;
            *(uint ***)(pbVar17 + -0x44) = param_10;
            *(uint ***)(pbVar17 + -0x40) = param_11;
            if (((uint)param_8 & 1) != 0) {
              bVar3 = RwReadStream((int *)ppppuVar2,&param_9,0xc);
              if (CONCAT31(extraout_var_39,bVar3) == 0) {
                return false;
              }
              iVar5 = 3;
              pppuVar9 = &param_9;
              do {
                ppuVar16 = *pppuVar9;
                iVar5 = iVar5 + -1;
                *pppuVar9 = (uint **)(((uint)ppuVar16 & 0xff00 | (int)ppuVar16 << 0x10) << 8 |
                                     ((uint)ppuVar16 & 0xff0000 | (uint)ppuVar16 >> 0x10) >> 8);
                pppuVar9 = pppuVar9 + 1;
              } while (iVar5 != 0);
              *(uint ***)(pbVar17 + 4) = param_9;
              *(uint ***)(pbVar17 + 8) = param_10;
              *(uint ***)(pbVar17 + 0xc) = param_11;
              *pbVar17 = *pbVar17 | 0x40;
            }
            if (((uint)param_8 & 2) != 0) {
              bVar3 = RwReadStream((int *)ppppuVar2,&param_9,8);
              if (CONCAT31(extraout_var_40,bVar3) == 0) {
                return false;
              }
              iVar5 = 2;
              pppuVar9 = &param_9;
              do {
                ppuVar16 = *pppuVar9;
                iVar5 = iVar5 + -1;
                *pppuVar9 = (uint **)(((uint)ppuVar16 & 0xff00 | (int)ppuVar16 << 0x10) << 8 |
                                     ((uint)ppuVar16 & 0xff0000 | (uint)ppuVar16 >> 0x10) >> 8);
                pppuVar9 = pppuVar9 + 1;
              } while (iVar5 != 0);
              lVar23 = __ftol();
              *(int *)(pbVar17 + 0x1c) = (int)lVar23;
              lVar23 = __ftol();
              *(int *)(pbVar17 + 0x20) = (int)lVar23;
            }
            if (((uint)param_8 & 4) != 0) {
              bVar3 = RwReadStream((int *)ppppuVar2,&param_9,0xc);
              if (CONCAT31(extraout_var_41,bVar3) == 0) {
                return false;
              }
              iVar5 = 3;
              pppuVar9 = &param_9;
              do {
                ppuVar16 = *pppuVar9;
                iVar5 = iVar5 + -1;
                *pppuVar9 = (uint **)(((uint)ppuVar16 & 0xff00 | (int)ppuVar16 << 0x10) << 8 |
                                     ((uint)ppuVar16 & 0xff0000 | (uint)ppuVar16 >> 0x10) >> 8);
                pppuVar9 = pppuVar9 + 1;
              } while (iVar5 != 0);
              lVar23 = __ftol();
              *(int *)(pbVar17 + 0x10) = (int)lVar23;
              lVar23 = __ftol();
              *(int *)(pbVar17 + 0x14) = (int)lVar23;
              lVar23 = __ftol();
              *(int *)(pbVar17 + 0x18) = (int)lVar23;
            }
            pbVar17[0x28] = 0;
            pbVar17[0x29] = 0;
            pbVar17[0x2a] = 0;
            pbVar17[0x2b] = 0;
            pbVar17[0x26] = 0;
            pbVar17[0x27] = 0;
            pbVar17[0x24] = 0;
            pbVar17[0x25] = 0;
            if (param_2 != 0) {
              RwSeekStream((int *)ppppuVar2,param_2);
            }
            pbVar17 = pbVar17 + 0x74;
            uVar15 = uVar15 + 1;
          } while (uVar15 < param_6);
          return true;
        }
        return false;
      }
      return false;
    }
  }
  bVar3 = RwReadStream((int *)ppppuVar2,&param_3,4);
  if (CONCAT31(extraout_var_00,bVar3) != 0) {
    param_3 = (param_3 >> 0x10 | param_3 & 0xff0000) >> 8 |
              (param_3 << 0x10 | param_3 & 0xff00) << 8;
    if (param_3 == 0) {
      bVar3 = true;
      goto LAB_1003a028;
    }
    iVar5 = RwSeekStream((int *)ppppuVar2,param_3);
    bVar3 = true;
    if (iVar5 != 0) goto LAB_1003a028;
  }
  bVar3 = false;
LAB_1003a028:
  if (!bVar3) {
    FUN_1000cba0(0x59);
  }
  return false;
}


