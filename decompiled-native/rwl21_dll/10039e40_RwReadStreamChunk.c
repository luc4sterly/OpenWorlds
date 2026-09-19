// 10039e40 RwReadStreamChunk [Global]
// programa: RWL21.DLL

/* WARNING: Type propagation algorithm not settling */

bool RwReadStreamChunk(uint ****param_1,int param_2,int *param_3)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar4;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  undefined3 extraout_var_05;
  undefined3 extraout_var_06;
  undefined3 extraout_var_07;
  undefined3 extraout_var_08;
  undefined4 *puVar5;
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
  int *piVar6;
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
  uint *puVar7;
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
  uint ***pppuVar8;
  undefined3 extraout_var_66;
  undefined3 extraout_var_67;
  undefined3 extraout_var_68;
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
  uint **ppuVar9;
  undefined3 extraout_var_83;
  undefined3 extraout_var_84;
  undefined3 extraout_var_85;
  undefined3 extraout_var_86;
  undefined3 extraout_var_87;
  undefined3 extraout_var_88;
  undefined3 extraout_var_89;
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
  uint ***pppuVar10;
  uint **ppuVar11;
  uint *unaff_EBX;
  undefined4 unaff_EBP;
  int *unaff_ESI;
  byte *pbVar12;
  uint *puVar13;
  int *piVar14;
  undefined4 *unaff_EDI;
  int *piVar15;
  uint *puVar16;
  uint **ppuVar17;
  longlong lVar18;
  int *unaff_retaddr;
  uint **in_stack_00000010;
  undefined4 uVar19;
  uint uVar20;
  uint **ppuStack_8c;
  uint **ppuStack_88;
  uint uStack_84;
  undefined4 uStack_80;
  uint auStack_7c [2];
  uint **ppuStack_74;
  uint uStack_70;
  uint **appuStack_6c [3];
  uint **ppuStack_60;
  uint **ppuStack_5c;
  uint **ppuStack_58;
  uint **ppuStack_54;
  uint **ppuStack_50;
  uint **ppuStack_4c;
  uint **ppuStack_48;
  uint **ppuStack_44;
  uint **ppuStack_40;
  uint **ppuStack_3c;
  uint **ppuStack_38;
  float fStack_30;
  float fStack_2c;
  float fStack_20;
  float fStack_1c;
  uint uStack_18;
  uint uStack_14;
  int *piStack_10;
  int iStack_c;
  undefined4 *puStack_8;
  undefined4 *puStack_4;
  
                    /* 0x39e40  324  RwReadStreamChunk */
  if (param_3 == (int *)0x0) {
    FUN_1000cba0(1);
    return false;
  }
  bVar2 = RwReadStream((int *)param_1,auStack_7c + 2,4);
  if (CONCAT31(extraout_var,bVar2) == 0) {
    return false;
  }
  ppuVar11 = (uint **)(((int)ppuStack_74 << 0x10 | (uint)ppuStack_74 & 0xff00) << 8 |
                      ((uint)ppuStack_74 >> 0x10 | (uint)ppuStack_74 & 0xff0000) >> 8);
  ppuStack_74 = ppuVar11;
  if (param_2 < 0x43414d46) {
    if (param_2 == 0x43414d45) {
      do {
        bVar2 = RwReadStream((int *)param_1,&uStack_84,4);
        if (CONCAT31(extraout_var_54,bVar2) == 0) break;
        uStack_84 = (uStack_84 & 0xff00 | uStack_84 << 0x10) << 8 |
                    (uStack_84 & 0xff0000 | uStack_84 >> 0x10) >> 8;
        if (uStack_84 == 0x53545254) {
          bVar2 = true;
          goto LAB_1003ba76;
        }
        iVar4 = RwSkipStreamChunk((int *)param_1);
      } while (iVar4 != 0);
      bVar2 = false;
LAB_1003ba76:
      if (!bVar2) {
        FUN_1000cba0(0x5a);
        return false;
      }
      bVar2 = RwReadStreamChunk(param_1,0x53545254,(int *)(appuStack_6c + 2));
      if (CONCAT31(extraout_var_55,bVar2) == 0) {
        return false;
      }
      pppuVar8 = appuStack_6c;
      iVar4 = 0x17;
      do {
        pppuVar8 = pppuVar8 + 1;
        ppuVar11 = *pppuVar8;
        iVar4 = iVar4 + -1;
        *pppuVar8 = (uint **)(((uint)ppuVar11 & 0xff00 | (int)ppuVar11 << 0x10) << 8 |
                             ((uint)ppuVar11 & 0xff0000 | (uint)ppuVar11 >> 0x10) >> 8);
      } while (iVar4 != 0);
      puVar7 = RwCreateCamera(ppuStack_3c,ppuStack_38,(undefined4 *)0x0);
      if (puVar7 == (uint *)0x0) {
        return false;
      }
      RwSetCameraProjection((int)puVar7,(int)appuStack_6c[1]);
      RwSetCameraBackColor((uint)puVar7,uStack_18,uStack_14,(uint)piStack_10);
      RwSetCameraNearClipping((int)puVar7,fStack_30);
      RwSetCameraFarClipping((int)puVar7,fStack_2c);
      RwSetCameraBackdropOffset((int)puVar7,appuStack_6c[2],ppuStack_60);
      RwSetCameraBackdropViewportRect
                ((int)puVar7,(int)ppuStack_5c,(int)ppuStack_58,(int)ppuStack_54,(int)ppuStack_50);
      RwSetCameraViewport((int)puVar7,(int)ppuStack_4c,(int)ppuStack_48,(int)ppuStack_44,
                          (int)ppuStack_40);
      RwSetCameraViewwindow((int)puVar7,fStack_20,fStack_1c);
      do {
        bVar2 = RwReadStream((int *)param_1,&ppuStack_88,4);
        if (CONCAT31(extraout_var_56,bVar2) == 0) break;
        ppuStack_88 = (uint **)(((uint)ppuStack_88 & 0xff00 | (int)ppuStack_88 << 0x10) << 8 |
                               ((uint)ppuStack_88 & 0xff0000 | (uint)ppuStack_88 >> 0x10) >> 8);
        if (ppuStack_88 == (uint **)0x4d415458) {
          bVar2 = true;
          goto LAB_1003bbf6;
        }
        iVar4 = RwSkipStreamChunk((int *)param_1);
      } while (iVar4 != 0);
      bVar2 = false;
LAB_1003bbf6:
      if (!bVar2) {
        RwDestroyCamera(puVar7);
        FUN_1000cba0(0x5a);
        return false;
      }
      bVar2 = RwReadStreamChunk(param_1,0x4d415458,(int *)&ppuStack_8c);
      if (CONCAT31(extraout_var_57,bVar2) == 0) {
        RwDestroyCamera(puVar7);
        return false;
      }
      puVar13 = unaff_EBX;
      puVar16 = puVar7;
      for (iVar4 = 0x11; puVar16 = puVar16 + 1, iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar16 = *puVar13;
        puVar13 = puVar13 + 1;
      }
      RwDestroyMatrix(unaff_EBX);
      do {
        bVar2 = RwReadStream((int *)param_1,&ppuStack_8c,4);
        if (CONCAT31(extraout_var_58,bVar2) == 0) break;
        ppuStack_8c = (uint **)(((uint)ppuStack_8c & 0xff00 | (int)ppuStack_8c << 0x10) << 8 |
                               ((uint)ppuStack_8c & 0xff0000 | (uint)ppuStack_8c >> 0x10) >> 8);
        if (ppuStack_8c == (uint **)0x56334420) {
          bVar2 = true;
          goto LAB_1003bcac;
        }
        iVar4 = RwSkipStreamChunk((int *)param_1);
      } while (iVar4 != 0);
      bVar2 = false;
LAB_1003bcac:
      if (!bVar2) {
        RwDestroyCamera(puVar7);
        FUN_1000cba0(0x5a);
        return false;
      }
      bVar2 = RwReadStreamChunk(param_1,0x56334420,(int *)&ppuStack_88);
      if (CONCAT31(extraout_var_59,bVar2) == 0) {
        RwDestroyCamera(puVar7);
        return false;
      }
      RwSetCameraViewOffset((int)puVar7,ppuStack_8c,ppuStack_88);
      if (ppuStack_3c != (uint **)0x0) {
        do {
          bVar2 = RwReadStream((int *)param_1,(undefined4 *)&stack0xffffff70,4);
          if (CONCAT31(extraout_var_60,bVar2) == 0) break;
          unaff_EBX = (uint *)(((uint)unaff_EBX & 0xff00 | (int)unaff_EBX << 0x10) << 8 |
                              ((uint)unaff_EBX & 0xff0000 | (uint)unaff_EBX >> 0x10) >> 8);
          if (unaff_EBX == (uint *)0x52415354) {
            bVar2 = true;
            goto LAB_1003bd66;
          }
          iVar4 = RwSkipStreamChunk((int *)param_1);
        } while (iVar4 != 0);
        bVar2 = false;
LAB_1003bd66:
        if (!bVar2) {
          RwDestroyCamera(puVar7);
          FUN_1000cba0(0x5a);
          return false;
        }
        bVar2 = RwReadStreamChunk(param_1,0x52415354,(int *)&stack0xffffff68);
        if (CONCAT31(extraout_var_61,bVar2) == 0) {
          RwDestroyCamera(puVar7);
          return false;
        }
        RwSetCameraBackdrop((int)puVar7,unaff_EBP);
      }
      *puStack_4 = puVar7;
      return true;
    }
    if (param_2 == 0x41544f4d) {
      do {
        bVar2 = RwReadStream((int *)param_1,&uStack_80,4);
        if (CONCAT31(extraout_var_42,bVar2) == 0) break;
        uStack_80 = (uStack_80 & 0xff00 | uStack_80 << 0x10) << 8 |
                    (uStack_80 & 0xff0000 | uStack_80 >> 0x10) >> 8;
        if (uStack_80 == 0x53545254) {
          bVar2 = true;
          goto LAB_1003b5c9;
        }
        iVar4 = RwSkipStreamChunk((int *)param_1);
      } while (iVar4 != 0);
      bVar2 = false;
LAB_1003b5c9:
      if (!bVar2) {
        FUN_1000cba0(0x5a);
        return false;
      }
      uVar20 = 0x34;
      bVar2 = RwReadStreamChunk(param_1,0x53545254,(int *)(appuStack_6c + 2));
      if (CONCAT31(extraout_var_43,bVar2) == 0) {
        return false;
      }
      pppuVar8 = appuStack_6c;
      iVar4 = 0xd;
      do {
        pppuVar8 = pppuVar8 + 1;
        ppuVar11 = *pppuVar8;
        iVar4 = iVar4 + -1;
        *pppuVar8 = (uint **)(((uint)ppuVar11 & 0xff00 | (int)ppuVar11 << 0x10) << 8 |
                             ((uint)ppuVar11 & 0xff0000 | (uint)ppuVar11 >> 0x10) >> 8);
      } while (iVar4 != 0);
      piVar6 = RwCreateClump(0,0);
      if (piVar6 == (int *)0x0) {
        return false;
      }
      piVar6[0x23] = (int)appuStack_6c[1];
      piVar6[0x24] = (int)appuStack_6c[2];
      piVar6[0x3a] = (int)ppuStack_60;
      piVar6[0x62] = 0;
      piVar6[99] = (int)ppuStack_44;
      piVar6[100] = (int)ppuStack_40;
      RwSetClumpLightSampleRate((int)piVar6,(float)ppuStack_38);
      if (((uint)ppuStack_38 & 0x7fffffff) == 0) {
        *(undefined1 *)((int)piVar6 + 0x19b) = 0;
      }
      do {
        bVar2 = RwReadStream((int *)param_1,&uStack_84,4);
        if (CONCAT31(extraout_var_44,bVar2) == 0) break;
        uStack_84 = (uStack_84 & 0xff00 | uStack_84 << 0x10) << 8 |
                    (uStack_84 & 0xff0000 | uStack_84 >> 0x10) >> 8;
        if (uStack_84 == 0x4d415458) {
          bVar2 = true;
          goto LAB_1003b70c;
        }
        iVar4 = RwSkipStreamChunk((int *)param_1);
      } while (iVar4 != 0);
      bVar2 = false;
LAB_1003b70c:
      if (!bVar2) {
        FUN_1000cba0(0x5a);
        return false;
      }
      bVar2 = RwReadStreamChunk(param_1,0x4d415458,(int *)&ppuStack_8c);
      if (CONCAT31(extraout_var_45,bVar2) == 0) {
        return false;
      }
      ppuVar11 = ppuStack_48;
      piVar14 = piVar6 + 0x3b;
      for (iVar4 = 0x11; iVar4 != 0; iVar4 = iVar4 + -1) {
        *piVar14 = (int)*ppuVar11;
        ppuVar11 = ppuVar11 + 1;
        piVar14 = piVar14 + 1;
      }
      RwDestroyMatrix(ppuStack_48);
      do {
        bVar2 = RwReadStream((int *)param_1,&ppuStack_88,4);
        if (CONCAT31(extraout_var_46,bVar2) == 0) break;
        ppuStack_88 = (uint **)(((uint)ppuStack_88 & 0xff00 | (int)ppuStack_88 << 0x10) << 8 |
                               ((uint)ppuStack_88 & 0xff0000 | (uint)ppuStack_88 >> 0x10) >> 8);
        if (ppuStack_88 == (uint **)0x4d415458) {
          bVar2 = true;
          goto LAB_1003b7b9;
        }
        iVar4 = RwSkipStreamChunk((int *)param_1);
      } while (iVar4 != 0);
      bVar2 = false;
LAB_1003b7b9:
      if (!bVar2) {
        FUN_1000cba0(0x5a);
        return false;
      }
      bVar2 = RwReadStreamChunk(param_1,0x4d415458,(int *)&stack0xffffff70);
      if (CONCAT31(extraout_var_47,bVar2) == 0) {
        return false;
      }
      piVar14 = unaff_ESI;
      piVar15 = piVar6 + 0x4c;
      for (iVar4 = 0x11; iVar4 != 0; iVar4 = iVar4 + -1) {
        *piVar15 = *piVar14;
        piVar14 = piVar14 + 1;
        piVar15 = piVar15 + 1;
      }
      RwDestroyMatrix(unaff_ESI);
      do {
        bVar2 = RwReadStream((int *)param_1,&ppuStack_8c,4);
        if (CONCAT31(extraout_var_48,bVar2) == 0) break;
        ppuStack_8c = (uint **)(((uint)ppuStack_8c >> 0x10 | (uint)ppuStack_8c & 0xff0000) >> 8 |
                               ((int)ppuStack_8c << 0x10 | (uint)ppuStack_8c & 0xff00) << 8);
        if (ppuStack_8c == (uint **)0x564c5354) {
          bVar2 = true;
          goto LAB_1003b866;
        }
        iVar4 = RwSkipStreamChunk((int *)param_1);
      } while (iVar4 != 0);
      bVar2 = false;
LAB_1003b866:
      if (!bVar2) {
        FUN_1000cba0(0x5a);
        return false;
      }
      bVar2 = RwReadStreamChunk(param_1,0x564c5354,piVar6);
      if (CONCAT31(extraout_var_49,bVar2) == 0) {
        return false;
      }
      do {
        bVar2 = RwReadStream((int *)param_1,(undefined4 *)&stack0xffffff70,4);
        if (CONCAT31(extraout_var_50,bVar2) == 0) break;
        ppuVar11 = (uint **)(((uint)ppuStack_48 & 0xff00 | (int)ppuStack_48 << 0x10) << 8 |
                            ((uint)ppuStack_48 & 0xff0000 | (uint)ppuStack_48 >> 0x10) >> 8);
        if (ppuVar11 == (uint **)0x504c5354) {
          bVar2 = true;
          goto LAB_1003b8fa;
        }
        iVar4 = RwSkipStreamChunk((int *)param_1);
        ppuStack_48 = ppuVar11;
      } while (iVar4 != 0);
      bVar2 = false;
LAB_1003b8fa:
      if (!bVar2) {
        FUN_1000cba0(0x5a);
        return false;
      }
      bVar2 = RwReadStreamChunk(param_1,0x504c5354,piVar6);
      if (CONCAT31(extraout_var_51,bVar2) == 0) {
        return false;
      }
      if (ppuStack_4c != (uint **)0x0) {
        ppuVar11 = (uint **)0x0;
LAB_1003b94a:
        do {
          bVar2 = RwReadStream((int *)param_1,(undefined4 *)&stack0xffffff68,4);
          if (CONCAT31(extraout_var_52,bVar2) == 0) {
LAB_1003b9a3:
            bVar2 = false;
          }
          else {
            unaff_EDI = (undefined4 *)
                        (((uint)unaff_EDI & 0xff00 | (int)unaff_EDI << 0x10) << 8 |
                        ((uint)unaff_EDI & 0xff0000 | (uint)unaff_EDI >> 0x10) >> 8);
            if (unaff_EDI != (undefined4 *)0x41544f4d) {
              iVar4 = RwSkipStreamChunk((int *)param_1);
              if (iVar4 == 0) goto LAB_1003b9a3;
              goto LAB_1003b94a;
            }
            bVar2 = true;
          }
          if (!bVar2) {
            FUN_1000cba0(0x5a);
            return false;
          }
          bVar2 = RwReadStreamChunk(param_1,0x41544f4d,(int *)&stack0xffffff6c);
          if (CONCAT31(extraout_var_53,bVar2) == 0) {
            return false;
          }
          ppuVar11 = (uint **)((int)ppuVar11 + 1);
          RwAddChildToClump((int)piVar6,(uint)unaff_EDI);
        } while (ppuVar11 < ppuStack_50);
      }
      RwSetClumpHints((int)piVar6,uVar20);
      piVar6[0x32] = 0;
      piVar6[0x31] = 0;
      *puStack_8 = piVar6;
      return true;
    }
  }
  else if (param_2 < 0x44415442) {
    if (param_2 == 0x44415441) {
      param_3[1] = (int)ppuVar11;
      puVar5 = (undefined4 *)(**(code **)(PTR_DAT_1005b69c + 0x34c))(ppuVar11);
      *param_3 = (int)puVar5;
      if (puVar5 == (undefined4 *)0x0) {
        FUN_1000cba0(3);
        return false;
      }
      bVar2 = RwReadStream((int *)param_1,puVar5,(uint)ppuStack_74);
      if (CONCAT31(extraout_var_09,bVar2) != 0) {
        return true;
      }
      (**(code **)(PTR_DAT_1005b69c + 0x358))(*param_3);
      return false;
    }
    if (param_2 == 0x434c554d) {
      DAT_1005b798 = FUN_10037030(DAT_1005b794);
      if (DAT_1005b798 != (int *)0x0) {
        piVar6 = FUN_10037030(DAT_1005b790);
        if (piVar6 != (int *)0x0) {
          iVar4 = (**(code **)(PTR_DAT_1005b69c + 0x34c))(0x28);
          *piVar6 = iVar4;
          if (iVar4 == 0) {
            if (piVar6 != (int *)0x0) {
              (**(code **)(PTR_DAT_1005b69c + 0x358))(0);
              FUN_10037010(DAT_1005b790,piVar6);
            }
            piVar6 = (int *)0x0;
          }
          else {
            piVar6[2] = 0;
            piVar6[1] = 10;
          }
        }
        *DAT_1005b798 = (int)piVar6;
        piVar6 = FUN_10037030(DAT_1005b790);
        if (piVar6 != (int *)0x0) {
          iVar4 = (**(code **)(PTR_DAT_1005b69c + 0x34c))(0x28);
          *piVar6 = iVar4;
          if (iVar4 == 0) {
            if (piVar6 != (int *)0x0) {
              (**(code **)(PTR_DAT_1005b69c + 0x358))(0);
              FUN_10037010(DAT_1005b790,piVar6);
            }
            piVar6 = (int *)0x0;
          }
          else {
            piVar6[2] = 0;
            piVar6[1] = 10;
          }
        }
        DAT_1005b798[1] = (int)piVar6;
        piVar6 = FUN_10037030(DAT_1005b790);
        if (piVar6 != (int *)0x0) {
          iVar4 = (**(code **)(PTR_DAT_1005b69c + 0x34c))(0x28);
          *piVar6 = iVar4;
          if (iVar4 == 0) {
            FUN_10039be0(piVar6);
            piVar6 = (int *)0x0;
          }
          else {
            piVar6[2] = 0;
            piVar6[1] = 10;
          }
        }
        DAT_1005b798[2] = (int)piVar6;
        piVar6 = FUN_10037030(DAT_1005b790);
        if (piVar6 != (int *)0x0) {
          iVar4 = (**(code **)(PTR_DAT_1005b69c + 0x34c))(0x28);
          *piVar6 = iVar4;
          if (iVar4 == 0) {
            FUN_10039be0(piVar6);
            piVar6 = (int *)0x0;
          }
          else {
            piVar6[2] = 0;
            piVar6[1] = 10;
          }
        }
        DAT_1005b798[3] = (int)piVar6;
        piVar6 = FUN_10039c20();
        DAT_1005b798[4] = (int)piVar6;
        DAT_1005b798[5] = 0;
        if ((((*DAT_1005b798 != 0) && (DAT_1005b798[1] != 0)) && (DAT_1005b798[2] != 0)) &&
           ((DAT_1005b798[3] != 0 && (DAT_1005b798[4] != 0)))) {
          do {
            bVar2 = RwReadStream((int *)param_1,&ppuStack_8c,4);
            if (CONCAT31(extraout_var_01,bVar2) == 0) break;
            ppuStack_8c = (uint **)(((uint)ppuStack_8c & 0xff00 | (int)ppuStack_8c << 0x10) << 8 |
                                   ((uint)ppuStack_8c & 0xff0000 | (uint)ppuStack_8c >> 0x10) >> 8);
            if (ppuStack_8c == (uint **)0x52414c54) {
              bVar2 = true;
              goto LAB_1003a260;
            }
            iVar4 = RwSkipStreamChunk((int *)param_1);
          } while (iVar4 != 0);
          bVar2 = false;
LAB_1003a260:
          if (bVar2) {
            bVar2 = RwReadStreamChunk(param_1,0x52414c54,(int *)param_1);
            if (CONCAT31(extraout_var_02,bVar2) == 0) {
              bVar2 = false;
            }
            else {
              do {
                bVar2 = RwReadStream((int *)param_1,(undefined4 *)&stack0xffffff70,4);
                if (CONCAT31(extraout_var_03,bVar2) == 0) break;
                unaff_EBX = (uint *)(((uint)unaff_EBX & 0xff00 | (int)unaff_EBX << 0x10) << 8 |
                                    ((uint)unaff_EBX & 0xff0000 | (uint)unaff_EBX >> 0x10) >> 8);
                if (unaff_EBX == (uint *)0x54454c54) {
                  bVar2 = true;
                  goto LAB_1003a2f4;
                }
                iVar4 = RwSkipStreamChunk((int *)param_1);
              } while (iVar4 != 0);
              bVar2 = false;
LAB_1003a2f4:
              if (bVar2) {
                bVar2 = RwReadStreamChunk(param_1,0x54454c54,(int *)param_1);
                if (CONCAT31(extraout_var_04,bVar2) == 0) {
                  bVar2 = false;
                }
                else {
                  do {
                    bVar2 = RwReadStream((int *)param_1,(undefined4 *)&stack0xffffff6c,4);
                    if (CONCAT31(extraout_var_05,bVar2) == 0) break;
                    unaff_ESI = (int *)(((uint)unaff_ESI & 0xff00 | (int)unaff_ESI << 0x10) << 8 |
                                       ((uint)unaff_ESI & 0xff0000 | (uint)unaff_ESI >> 0x10) >> 8);
                    if (unaff_ESI == (int *)0x4d414c54) {
                      bVar2 = true;
                      goto LAB_1003a388;
                    }
                    iVar4 = RwSkipStreamChunk((int *)param_1);
                  } while (iVar4 != 0);
                  bVar2 = false;
LAB_1003a388:
                  if (bVar2) {
                    bVar3 = RwReadStreamChunk(param_1,0x4d414c54,(int *)param_1);
                    bVar2 = false;
                    if (CONCAT31(extraout_var_06,bVar3) != 0) {
                      bVar2 = true;
                      DAT_1005b798[5] = 1;
                    }
                  }
                  else {
                    FUN_1000cba0(0x5a);
                    bVar2 = false;
                  }
                }
              }
              else {
                FUN_1000cba0(0x5a);
                bVar2 = false;
              }
            }
          }
          else {
            FUN_1000cba0(0x5a);
            bVar2 = false;
          }
          if (!bVar2) {
            FUN_1003d550();
            return false;
          }
          do {
            bVar2 = RwReadStream((int *)param_1,&ppuStack_8c,4);
            if (CONCAT31(extraout_var_07,bVar2) == 0) break;
            ppuStack_8c = (uint **)(((uint)ppuStack_8c & 0xff00 | (int)ppuStack_8c << 0x10) << 8 |
                                   ((uint)ppuStack_8c & 0xff0000 | (uint)ppuStack_8c >> 0x10) >> 8);
            if (ppuStack_8c == (uint **)0x41544f4d) {
              bVar2 = true;
              goto LAB_1003a435;
            }
            iVar4 = RwSkipStreamChunk((int *)param_1);
          } while (iVar4 != 0);
          bVar2 = false;
LAB_1003a435:
          if (!bVar2) {
            FUN_1003d550();
            FUN_1000cba0(0x5a);
            return false;
          }
          bVar2 = RwReadStreamChunk(param_1,0x41544f4d,&uStack_80);
          if (CONCAT31(extraout_var_08,bVar2) != 0) {
            FUN_1003d550();
            uRam434c554d = uStack_84;
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
  else if (param_2 < 0x4d414c55) {
    if (param_2 == 0x4d414c54) {
      do {
        bVar2 = RwReadStream((int *)param_1,&uStack_80,4);
        if (CONCAT31(extraout_var_66,bVar2) == 0) break;
        uStack_80 = (uStack_80 & 0xff00 | uStack_80 << 0x10) << 8 |
                    (uStack_80 & 0xff0000 | uStack_80 >> 0x10) >> 8;
        if (uStack_80 == 0x53545254) {
          bVar2 = true;
          goto LAB_1003c02e;
        }
        iVar4 = RwSkipStreamChunk((int *)param_1);
      } while (iVar4 != 0);
      bVar2 = false;
LAB_1003c02e:
      if (!bVar2) {
        FUN_1000cba0(0x5a);
        return false;
      }
      bVar2 = RwReadStreamChunk(param_1,0x53545254,(int *)(auStack_7c + 3));
      if (CONCAT31(extraout_var_67,bVar2) == 0) {
        return false;
      }
      iVar4 = 3;
      puVar7 = auStack_7c + 2;
      do {
        uVar20 = *puVar7;
        iVar4 = iVar4 + -1;
        *puVar7 = (uVar20 & 0xff00 | uVar20 << 0x10) << 8 |
                  (uVar20 & 0xff0000 | uVar20 >> 0x10) >> 8;
        puVar7 = puVar7 + 1;
      } while (iVar4 != 0);
      ppuStack_8c = (uint **)0x0;
      if (ppuStack_74 == (uint **)0x0) {
        return true;
      }
      do {
        bVar2 = RwReadStream((int *)param_1,appuStack_6c + 1,0x28);
        if (CONCAT31(extraout_var_68,bVar2) == 0) {
          return false;
        }
        if (0x28 < uStack_70) {
          RwSeekStream((int *)param_1,uStack_70 - 0x28);
        }
        pppuVar8 = appuStack_6c;
        iVar4 = 10;
        do {
          pppuVar8 = pppuVar8 + 1;
          ppuVar11 = *pppuVar8;
          iVar4 = iVar4 + -1;
          *pppuVar8 = (uint **)(((uint)ppuVar11 & 0xff00 | (int)ppuVar11 << 0x10) << 8 |
                               ((uint)ppuVar11 & 0xff0000 | (uint)ppuVar11 >> 0x10) >> 8);
        } while (iVar4 != 0);
        puVar7 = RwCreateMaterial();
        if (puVar7 == (uint *)0x0) {
          return false;
        }
        *puVar7 = (uint)appuStack_6c[2];
        *(undefined1 *)(puVar7 + 0xc) = ppuStack_60._0_1_;
        RwSetMaterialColor((int)puVar7,(uint)ppuStack_5c,(uint)ppuStack_58,(uint)ppuStack_54);
        RwSetMaterialOpacity(puVar7,(uint)ppuStack_50);
        RwSetMaterialSurface((int)puVar7,(uint)ppuStack_4c,(uint)ppuStack_48,(uint)ppuStack_44);
        if (appuStack_6c[1] != (uint **)0x0) {
          if (((uint **)((int *)DAT_1005b798[1])[2] < appuStack_6c[1]) ||
             (appuStack_6c[1] == (uint **)0x0)) {
            uVar20 = 0;
          }
          else {
            uVar20 = *(uint *)(*(int *)DAT_1005b798[1] + -4 + (int)appuStack_6c[1] * 4);
          }
          RwSetMaterialTexture(puVar7,uVar20);
        }
        piVar14 = (int *)DAT_1005b798[2];
        piVar6 = (int *)(*piVar14 + piVar14[2] * 4);
        iVar4 = piVar14[2];
        do {
          piVar6 = piVar6 + -1;
          if (iVar4 == 0) {
            uVar20 = piVar14[1];
            if (uVar20 <= (uint)piVar14[2]) {
              iVar4 = (**(code **)(PTR_DAT_1005b69c + 0x354))(*piVar14,uVar20 * 4 + 0xa0);
              if (iVar4 == 0) break;
              *piVar14 = iVar4;
              piVar14[1] = uVar20 + 0x28;
            }
            *(uint **)(*piVar14 + piVar14[2] * 4) = puVar7;
            piVar14[2] = piVar14[2] + 1;
            break;
          }
          iVar4 = iVar4 + -1;
        } while ((uint *)*piVar6 != puVar7);
        ppuStack_8c = (uint **)((int)ppuStack_8c + 1);
        if (ppuStack_74 <= ppuStack_8c) {
          return true;
        }
      } while( true );
    }
    if (param_2 == 0x4c495445) {
      do {
        bVar2 = RwReadStream((int *)param_1,&ppuStack_8c,4);
        if (CONCAT31(extraout_var_62,bVar2) == 0) break;
        ppuStack_8c = (uint **)(((uint)ppuStack_8c & 0xff0000 | (uint)ppuStack_8c >> 0x10) >> 8 |
                               ((uint)ppuStack_8c & 0xff00 | (int)ppuStack_8c << 0x10) << 8);
        if (ppuStack_8c == (uint **)0x53545254) {
          bVar2 = true;
          goto LAB_1003be23;
        }
        iVar4 = RwSkipStreamChunk((int *)param_1);
      } while (iVar4 != 0);
      bVar2 = false;
LAB_1003be23:
      if (!bVar2) {
        FUN_1000cba0(0x5a);
        return false;
      }
      bVar2 = RwReadStreamChunk(param_1,0x53545254,(int *)(appuStack_6c + 2));
      if (CONCAT31(extraout_var_63,bVar2) == 0) {
        return false;
      }
      do {
        bVar2 = RwReadStream((int *)param_1,(undefined4 *)&stack0xffffff70,4);
        if (CONCAT31(extraout_var_64,bVar2) == 0) break;
        unaff_EBX = (uint *)(((uint)unaff_EBX & 0xff00 | (int)unaff_EBX << 0x10) << 8 |
                            ((uint)unaff_EBX & 0xff0000 | (uint)unaff_EBX >> 0x10) >> 8);
        if (unaff_EBX == (uint *)0x4d415458) {
          bVar2 = true;
          goto LAB_1003beb5;
        }
        iVar4 = RwSkipStreamChunk((int *)param_1);
      } while (iVar4 != 0);
      bVar2 = false;
LAB_1003beb5:
      if (!bVar2) {
        FUN_1000cba0(0x5a);
        return false;
      }
      bVar2 = RwReadStreamChunk(param_1,0x4d415458,(int *)&uStack_84);
      if (CONCAT31(extraout_var_65,bVar2) != 0) {
        pppuVar8 = (uint ***)RwCreateLight(1,0.0,1.0,0.0,0.0);
        if (pppuVar8 != (uint ***)0x0) {
          ppuVar11 = ppuStack_88;
          pppuVar10 = pppuVar8 + 2;
          for (iVar4 = 0x11; iVar4 != 0; iVar4 = iVar4 + -1) {
            *pppuVar10 = (uint **)*ppuVar11;
            ppuVar11 = ppuVar11 + 1;
            pppuVar10 = pppuVar10 + 1;
          }
          iVar4 = 0xe;
          RwDestroyMatrix(ppuStack_88);
          pppuVar10 = appuStack_6c;
          do {
            ppuVar11 = *pppuVar10;
            iVar4 = iVar4 + -1;
            *pppuVar10 = (uint **)(((uint)ppuVar11 & 0xff00 | (int)ppuVar11 << 0x10) << 8 |
                                  ((uint)ppuVar11 & 0xff0000 | (uint)ppuVar11 >> 0x10) >> 8);
            pppuVar10 = pppuVar10 + 1;
          } while (iVar4 != 0);
          pppuVar8[1] = appuStack_6c[0];
          pppuVar8[0x21] = appuStack_6c[1];
          pppuVar8[0x19] = appuStack_6c[2];
          pppuVar8[0x1a] = ppuStack_60;
          pppuVar8[0x1b] = ppuStack_5c;
          pppuVar8[0x1c] = ppuStack_58;
          pppuVar8[0x1d] = ppuStack_54;
          pppuVar8[0x1e] = ppuStack_4c;
          pppuVar8[0x1f] = ppuStack_48;
          pppuVar8[0x20] = ppuStack_44;
          pppuVar8[0x16] = ppuStack_40;
          pppuVar8[0x17] = ppuStack_3c;
          pppuVar8[0x18] = ppuStack_38;
          *param_1 = pppuVar8;
          return true;
        }
        RwDestroyMatrix(ppuStack_88);
        return false;
      }
      return false;
    }
  }
  else if (param_2 < 0x4d415459) {
    if (param_2 == 0x4d415458) {
      do {
        bVar2 = RwReadStream((int *)param_1,&uStack_80,4);
        if (CONCAT31(extraout_var_73,bVar2) == 0) break;
        uStack_80 = (uStack_80 & 0xff00 | uStack_80 << 0x10) << 8 |
                    (uStack_80 & 0xff0000 | uStack_80 >> 0x10) >> 8;
        if (uStack_80 == 0x53545254) {
          bVar2 = true;
          goto LAB_1003c448;
        }
        iVar4 = RwSkipStreamChunk((int *)param_1);
      } while (iVar4 != 0);
      bVar2 = false;
LAB_1003c448:
      if (!bVar2) {
        FUN_1000cba0(0x5a);
        return false;
      }
      bVar2 = RwReadStreamChunk(param_1,0x53545254,(int *)(appuStack_6c + 2));
      if (CONCAT31(extraout_var_74,bVar2) != 0) {
        puRam4d415458 = RwCreateMatrix();
        if (puRam4d415458 != (undefined4 *)0x0) {
          pppuVar8 = appuStack_6c;
          iVar4 = 0x10;
          do {
            pppuVar8 = pppuVar8 + 1;
            ppuVar11 = *pppuVar8;
            iVar4 = iVar4 + -1;
            *pppuVar8 = (uint **)(((uint)ppuVar11 & 0xff00 | (int)ppuVar11 << 0x10) << 8 |
                                 ((uint)ppuVar11 & 0xff0000 | (uint)ppuVar11 >> 0x10) >> 8);
          } while (iVar4 != 0);
          RwSetMatrixElements(puRam4d415458,appuStack_6c + 1);
          return true;
        }
        return false;
      }
      return false;
    }
    if (param_2 == 0x4d415452) {
      do {
        bVar2 = RwReadStream((int *)param_1,&ppuStack_8c,4);
        if (CONCAT31(extraout_var_69,bVar2) == 0) break;
        ppuStack_8c = (uint **)(((uint)ppuStack_8c & 0xff00 | (int)ppuStack_8c << 0x10) << 8 |
                               ((uint)ppuStack_8c & 0xff0000 | (uint)ppuStack_8c >> 0x10) >> 8);
        if (ppuStack_8c == (uint **)0x53545254) {
          bVar2 = true;
          goto LAB_1003c26b;
        }
        iVar4 = RwSkipStreamChunk((int *)param_1);
      } while (iVar4 != 0);
      bVar2 = false;
LAB_1003c26b:
      if (!bVar2) {
        FUN_1000cba0(0x5a);
        return false;
      }
      bVar2 = RwReadStreamChunk(param_1,0x53545254,(int *)(appuStack_6c + 2));
      if (CONCAT31(extraout_var_70,bVar2) == 0) {
        return false;
      }
      pppuVar8 = appuStack_6c;
      iVar4 = 10;
      do {
        pppuVar8 = pppuVar8 + 1;
        ppuVar11 = *pppuVar8;
        iVar4 = iVar4 + -1;
        *pppuVar8 = (uint **)(((uint)ppuVar11 & 0xff00 | (int)ppuVar11 << 0x10) << 8 |
                             ((uint)ppuVar11 & 0xff0000 | (uint)ppuVar11 >> 0x10) >> 8);
      } while (iVar4 != 0);
      pppuVar8 = (uint ***)RwCreateMaterial();
      if (pppuVar8 == (uint ***)0x0) {
        return false;
      }
      *pppuVar8 = appuStack_6c[2];
      *(undefined1 *)(pppuVar8 + 0xc) = ppuStack_60._0_1_;
      RwSetMaterialColor((int)pppuVar8,(uint)ppuStack_5c,(uint)ppuStack_58,(uint)ppuStack_54);
      RwSetMaterialOpacity((uint *)pppuVar8,(uint)ppuStack_50);
      RwSetMaterialSurface((int)pppuVar8,(uint)ppuStack_4c,(uint)ppuStack_48,(uint)ppuStack_44);
      if (appuStack_6c[1] != (uint **)0x0) {
        do {
          bVar2 = RwReadStream((int *)param_1,(undefined4 *)&stack0xffffff70,4);
          if (CONCAT31(extraout_var_71,bVar2) == 0) break;
          unaff_EBX = (uint *)(((int)unaff_EBX << 0x10 | (uint)unaff_EBX & 0xff00) << 8 |
                              ((uint)unaff_EBX >> 0x10 | (uint)unaff_EBX & 0xff0000) >> 8);
          if (unaff_EBX == (uint *)0x54455855) {
            bVar2 = true;
            goto LAB_1003c397;
          }
          iVar4 = RwSkipStreamChunk((int *)param_1);
        } while (iVar4 != 0);
        bVar2 = false;
LAB_1003c397:
        if (!bVar2) {
          FUN_1000cba0(0x5a);
          return false;
        }
        bVar2 = RwReadStreamChunk(param_1,0x54455855,(int *)&uStack_84);
        ppuStack_48 = ppuStack_88;
        if (CONCAT31(extraout_var_72,bVar2) == 0) {
          return false;
        }
      }
      RwSetMaterialTexture((uint *)pppuVar8,(uint)ppuStack_48);
      *param_1 = pppuVar8;
      return true;
    }
  }
  else if (param_2 < 0x504c5355) {
    if (param_2 == 0x504c5354) {
      do {
        bVar2 = RwReadStream((int *)param_1,&uStack_80,4);
        if (CONCAT31(extraout_var_11,bVar2) == 0) break;
        uStack_80 = (uStack_80 & 0xff00 | uStack_80 << 0x10) << 8 |
                    (uStack_80 & 0xff0000 | uStack_80 >> 0x10) >> 8;
        if (uStack_80 == 0x53545254) {
          bVar2 = true;
          goto LAB_1003a5e3;
        }
        iVar4 = RwSkipStreamChunk((int *)param_1);
      } while (iVar4 != 0);
      bVar2 = false;
LAB_1003a5e3:
      if (!bVar2) {
        FUN_1000cba0(0x5a);
        return false;
      }
      bVar2 = RwReadStreamChunk(param_1,0x53545254,(int *)(auStack_7c + 3));
      if (CONCAT31(extraout_var_12,bVar2) == 0) {
        return false;
      }
      iVar4 = 3;
      puVar7 = auStack_7c + 2;
      do {
        uVar20 = *puVar7;
        iVar4 = iVar4 + -1;
        *puVar7 = (uVar20 & 0xff00 | uVar20 << 0x10) << 8 |
                  (uVar20 & 0xff0000 | uVar20 >> 0x10) >> 8;
        puVar7 = puVar7 + 1;
      } while (iVar4 != 0);
      puVar5 = FUN_10020b70((int)ppuStack_74);
      if (puVar5 == (undefined4 *)0x0) {
        return false;
      }
      FUN_10020be0(puRam504c53ec);
      iVar4 = (((uint)appuStack_6c[0] & 0x10) >> 2) +
              (((int)appuStack_6c[0] << 0x1d) >> 0x1f & 0xcU) + 8 +
              (((int)appuStack_6c[0] << 0x1f) >> 0x1f & 0xcU);
      if (iVar4 < (int)uStack_70) {
        uStack_84 = uStack_70 - iVar4;
      }
      else {
        uStack_84 = 0;
      }
      ppuStack_8c = (uint **)0x0;
      puRam504c53ec = puVar5;
      if (ppuStack_74 == (uint **)0x0) {
        return true;
      }
      while( true ) {
        bVar2 = RwReadStream((int *)param_1,appuStack_6c + 1,8);
        if (CONCAT31(extraout_var_13,bVar2) == 0) {
          return false;
        }
        pppuVar8 = appuStack_6c;
        iVar4 = 2;
        do {
          pppuVar8 = pppuVar8 + 1;
          ppuVar11 = *pppuVar8;
          iVar4 = iVar4 + -1;
          *pppuVar8 = (uint **)(((uint)ppuVar11 & 0xff00 | (int)ppuVar11 << 0x10) << 8 |
                               ((uint)ppuVar11 & 0xff0000 | (uint)ppuVar11 >> 0x10) >> 8);
        } while (iVar4 != 0);
        bVar2 = RwReadStream((int *)param_1,&DAT_1005e070,(int)appuStack_6c[2] << 2);
        if (CONCAT31(extraout_var_14,bVar2) == 0) {
          return false;
        }
        puVar7 = &DAT_1005e070;
        for (uVar20 = (uint)appuStack_6c[2] & 0x3fffffff; uVar20 != 0; uVar20 = uVar20 - 1) {
          uVar1 = *puVar7;
          *puVar7 = (uVar1 & 0xff00 | uVar1 << 0x10) << 8 | (uVar1 & 0xff0000 | uVar1 >> 0x10) >> 8;
          puVar7 = puVar7 + 1;
        }
        puVar5 = FUN_10001220((int)appuStack_6c[2],iRam504c53dc,&DAT_1005e070);
        if (puVar5 == (undefined4 *)0x0) {
          return false;
        }
        bVar2 = FUN_10003660(0x504c5354,puVar5);
        if (CONCAT31(extraout_var_15,bVar2) == 0) {
          return false;
        }
        if (((uint **)((int *)DAT_1005b798[2])[2] < appuStack_6c[1]) ||
           (appuStack_6c[1] == (uint **)0x0)) {
          piVar6 = (int *)0x0;
        }
        else {
          piVar6 = *(int **)(*(int *)DAT_1005b798[2] + -4 + (int)appuStack_6c[1] * 4);
        }
        RwSetPolygonMaterial(puVar5,piVar6);
        if (((uint)appuStack_6c[0] & 1) != 0) {
          bVar2 = RwReadStream((int *)param_1,appuStack_6c + 1,0xc);
          if (CONCAT31(extraout_var_16,bVar2) == 0) {
            return false;
          }
          pppuVar8 = appuStack_6c;
          iVar4 = 3;
          do {
            pppuVar8 = pppuVar8 + 1;
            ppuVar11 = *pppuVar8;
            iVar4 = iVar4 + -1;
            *pppuVar8 = (uint **)(((uint)ppuVar11 & 0xff00 | (int)ppuVar11 << 0x10) << 8 |
                                 ((uint)ppuVar11 & 0xff0000 | (uint)ppuVar11 >> 0x10) >> 8);
          } while (iVar4 != 0);
          puVar5[4] = appuStack_6c[1];
          puVar5[5] = appuStack_6c[2];
          puVar5[6] = ppuStack_60;
        }
        if (((uint)appuStack_6c[0] & 4) != 0) {
          bVar2 = RwReadStream((int *)param_1,appuStack_6c + 1,0xc);
          if (CONCAT31(extraout_var_17,bVar2) == 0) {
            return false;
          }
          pppuVar8 = appuStack_6c;
          iVar4 = 3;
          do {
            pppuVar8 = pppuVar8 + 1;
            ppuVar11 = *pppuVar8;
            iVar4 = iVar4 + -1;
            *pppuVar8 = (uint **)(((uint)ppuVar11 & 0xff00 | (int)ppuVar11 << 0x10) << 8 |
                                 ((uint)ppuVar11 & 0xff0000 | (uint)ppuVar11 >> 0x10) >> 8);
          } while (iVar4 != 0);
          lVar18 = __ftol();
          puVar5[1] = (int)lVar18;
          lVar18 = __ftol();
          puVar5[2] = (int)lVar18;
          lVar18 = __ftol();
          puVar5[3] = (int)lVar18;
        }
        if (((uint)appuStack_6c[0] & 0x10) != 0) {
          bVar2 = RwReadStream((int *)param_1,appuStack_6c + 1,4);
          if (CONCAT31(extraout_var_18,bVar2) == 0) {
            return false;
          }
          pppuVar8 = appuStack_6c;
          iVar4 = 1;
          do {
            pppuVar8 = pppuVar8 + 1;
            ppuVar11 = *pppuVar8;
            iVar4 = iVar4 + -1;
            *pppuVar8 = (uint **)(((uint)ppuVar11 & 0xff00 | (int)ppuVar11 << 0x10) << 8 |
                                 ((uint)ppuVar11 & 0xff0000 | (uint)ppuVar11 >> 0x10) >> 8);
          } while (iVar4 != 0);
          *(short *)(puVar5 + 0xe) = (short)appuStack_6c[1];
        }
        if ((uStack_84 != 0) && (iVar4 = RwSeekStream((int *)param_1,uStack_84), iVar4 == 0)) break;
        ppuStack_8c = (uint **)((int)ppuStack_8c + 1);
        if (ppuStack_74 <= ppuStack_8c) {
          return true;
        }
      }
      return false;
    }
    if (param_2 == 0x50414c4c) {
      iVar4 = 0;
      do {
        bVar2 = RwReadStream((int *)param_1,&uStack_80,(uint)ppuStack_74 >> 8);
        if (CONCAT31(extraout_var_10,bVar2) == 0) {
          return false;
        }
        if (ppuStack_74 < (uint **)0x400) {
          RwSeekStream((int *)param_1,4 - ((uint)ppuStack_74 >> 8));
        }
        iVar4 = iVar4 + 1;
        *(undefined1 *)param_3 = (undefined1)uStack_80;
        *(undefined1 *)((int)param_3 + 1) = uStack_80._1_1_;
        *(undefined1 *)((int)param_3 + 2) = uStack_80._2_1_;
        param_3 = param_3 + 1;
      } while (iVar4 < 0x100);
      return true;
    }
  }
  else if (param_2 < 0x52415355) {
    if (param_2 == 0x52415354) {
      do {
        bVar2 = RwReadStream((int *)param_1,&uStack_80,4);
        if (CONCAT31(extraout_var_79,bVar2) == 0) break;
        uStack_80 = (uStack_80 & 0xff00 | uStack_80 << 0x10) << 8 |
                    (uStack_80 & 0xff0000 | uStack_80 >> 0x10) >> 8;
        if (uStack_80 == 0x53545254) {
          bVar2 = true;
          goto LAB_1003c78a;
        }
        iVar4 = RwSkipStreamChunk((int *)param_1);
      } while (iVar4 != 0);
      bVar2 = false;
LAB_1003c78a:
      if (!bVar2) {
        FUN_1000cba0(0x5a);
        return false;
      }
      bVar2 = RwReadStreamChunk(param_1,0x53545254,(int *)(appuStack_6c + 2));
      if (CONCAT31(extraout_var_80,bVar2) == 0) {
        return false;
      }
      pppuVar8 = appuStack_6c;
      iVar4 = 10;
      do {
        pppuVar8 = pppuVar8 + 1;
        ppuVar11 = *pppuVar8;
        iVar4 = iVar4 + -1;
        *pppuVar8 = (uint **)(((uint)ppuVar11 & 0xff00 | (int)ppuVar11 << 0x10) << 8 |
                             ((uint)ppuVar11 & 0xff0000 | (uint)ppuVar11 >> 0x10) >> 8);
      } while (iVar4 != 0);
      do {
        bVar2 = RwReadStream((int *)param_1,&uStack_84,4);
        if (CONCAT31(extraout_var_81,bVar2) == 0) break;
        uStack_84 = (uStack_84 & 0xff00 | uStack_84 << 0x10) << 8 |
                    (uStack_84 & 0xff0000 | uStack_84 >> 0x10) >> 8;
        if (uStack_84 == 0x44415441) {
          bVar2 = true;
          goto LAB_1003c853;
        }
        iVar4 = RwSkipStreamChunk((int *)param_1);
      } while (iVar4 != 0);
      bVar2 = false;
LAB_1003c853:
      if (!bVar2) {
        FUN_1000cba0(0x5a);
        return false;
      }
      uVar19 = 0;
      bVar2 = RwReadStreamChunk(param_1,0x44415441,&iStack_c);
      piVar6 = piStack_10;
      if (CONCAT31(extraout_var_82,bVar2) == 0) {
        return false;
      }
      pppuVar8 = (uint ***)RwCreateRaster(appuStack_6c[0],appuStack_6c[1]);
      if (pppuVar8 != (uint ***)0x0) {
        if (((*pppuVar8 == ppuStack_5c) && (pppuVar8[1] == ppuStack_58)) &&
           ((pppuVar8[2] == ppuStack_54 &&
            (((pppuVar8[3] == ppuStack_50 && (pppuVar8[4] == ppuStack_4c)) &&
             (pppuVar8[5] == ppuStack_48)))))) {
          ppuVar11 = (uint **)RwGetRasterStride((int)pppuVar8);
          if (ppuVar11 < ppuStack_60) {
            ppuVar11 = ppuStack_60;
          }
          ppuVar9 = (uint **)RwGetRasterPixels((int)pppuVar8);
          ppuStack_8c = appuStack_6c[1];
          ppuStack_88 = ppuVar9;
          if (0 < (int)appuStack_6c[1]) {
            do {
              piVar14 = piVar6;
              ppuVar17 = ppuVar9;
              for (uVar20 = (uint)ppuVar11 >> 2; uVar20 != 0; uVar20 = uVar20 - 1) {
                *ppuVar17 = (uint *)*piVar14;
                piVar14 = piVar14 + 1;
                ppuVar17 = ppuVar17 + 1;
              }
              for (uVar20 = (uint)ppuVar11 & 3; uVar20 != 0; uVar20 = uVar20 - 1) {
                *(char *)ppuVar17 = (char)*piVar14;
                piVar14 = (int *)((int)piVar14 + 1);
                ppuVar17 = (uint **)((int)ppuVar17 + 1);
              }
              iVar4 = RwGetRasterStride((int)pppuVar8);
              ppuVar9 = (uint **)((int)ppuVar9 + iVar4);
              piVar6 = (int *)((int)piVar6 + (int)ppuStack_60);
              ppuStack_8c = (uint **)((int)ppuStack_8c - 1);
            } while (ppuStack_8c != (uint **)0x0);
          }
          RwReleaseRasterPixels((int)pppuVar8);
          goto LAB_1003ca0d;
        }
        puVar5 = FUN_10021050(0,0,0);
        if (puVar5 != (undefined4 *)0x0) {
          puVar5[7] = appuStack_6c[0];
          puVar5[8] = appuStack_6c[1];
          puVar5[9] = appuStack_6c[2];
          puVar5[10] = ppuStack_60;
          *puVar5 = ppuStack_5c;
          puVar5[1] = ppuStack_58;
          puVar5[2] = ppuStack_54;
          puVar5[3] = ppuStack_50;
          puVar5[4] = ppuStack_4c;
          puVar5[5] = ppuStack_48;
          puVar5[6] = piVar6;
          iVar4 = (**(code **)(PTR_DAT_1005b69c + 0x48))(puVar5,pppuVar8,8,uVar19);
          puVar5[6] = 0;
          RwDestroyRaster(puVar5);
          if (iVar4 != 0) goto LAB_1003ca0d;
          RwDestroyRaster(pppuVar8);
        }
      }
      pppuVar8 = (uint ***)0x0;
LAB_1003ca0d:
      if (pppuVar8 != (uint ***)0x0) {
        (**(code **)(PTR_DAT_1005b69c + 0x358))(piStack_10);
        *param_1 = pppuVar8;
        return true;
      }
      (**(code **)(PTR_DAT_1005b69c + 0x358))();
      return false;
    }
    if (param_2 == 0x52414c54) {
      do {
        bVar2 = RwReadStream((int *)param_1,&uStack_80,4);
        if (CONCAT31(extraout_var_75,bVar2) == 0) break;
        uStack_80 = (uStack_80 & 0xff00 | uStack_80 << 0x10) << 8 |
                    (uStack_80 & 0xff0000 | uStack_80 >> 0x10) >> 8;
        if (uStack_80 == 0x53545254) {
          bVar2 = true;
          goto LAB_1003c543;
        }
        iVar4 = RwSkipStreamChunk((int *)param_1);
      } while (iVar4 != 0);
      bVar2 = false;
LAB_1003c543:
      if (!bVar2) {
        FUN_1000cba0(0x5a);
        return false;
      }
      bVar2 = RwReadStreamChunk(param_1,0x53545254,(int *)(auStack_7c + 3));
      if (CONCAT31(extraout_var_76,bVar2) == 0) {
        return false;
      }
      iVar4 = 3;
      puVar7 = auStack_7c + 2;
      do {
        uVar20 = *puVar7;
        iVar4 = iVar4 + -1;
        *puVar7 = (uVar20 & 0xff00 | uVar20 << 0x10) << 8 |
                  (uVar20 & 0xff0000 | uVar20 >> 0x10) >> 8;
        puVar7 = puVar7 + 1;
      } while (iVar4 != 0);
      uVar20 = 0;
LAB_1003c5ae:
      do {
        if ((int)ppuStack_74 <= (int)uVar20) {
          return true;
        }
        do {
          bVar2 = RwReadStream((int *)param_1,&ppuStack_88,4);
          if (CONCAT31(extraout_var_77,bVar2) == 0) break;
          ppuStack_88 = (uint **)(((uint)ppuStack_88 & 0xff00 | (int)ppuStack_88 << 0x10) << 8 |
                                 ((uint)ppuStack_88 & 0xff0000 | (uint)ppuStack_88 >> 0x10) >> 8);
          if (ppuStack_88 == (uint **)0x52415354) {
            bVar2 = true;
            goto LAB_1003c61a;
          }
          iVar4 = RwSkipStreamChunk((int *)param_1);
        } while (iVar4 != 0);
        bVar2 = false;
LAB_1003c61a:
        if (!bVar2) {
          while (uVar1 = uVar20 - 1, -1 < (int)uVar1) {
            if ((uRam52414c5c < uVar20) || (uVar1 == 0xffffffff)) {
              puVar5 = (undefined4 *)0x0;
            }
            else {
              puVar5 = *(undefined4 **)(iRam52414c54 + uVar1 * 4);
            }
            RwDestroyRaster(puVar5);
            uVar20 = uVar1;
          }
          FUN_1000cba0(0x5a);
          return false;
        }
        piVar6 = param_3;
        bVar2 = RwReadStreamChunk(param_1,0x52415354,(int *)&ppuStack_8c);
        if (CONCAT31(extraout_var_78,bVar2) == 0) {
          while (uVar1 = uVar20 - 1, -1 < (int)uVar1) {
            if (((uint)((int *)*DAT_1005b798)[2] < uVar20) || (uVar1 == 0xffffffff)) {
              puVar5 = (undefined4 *)0x0;
            }
            else {
              puVar5 = *(undefined4 **)(*(int *)*DAT_1005b798 + uVar1 * 4);
            }
            RwDestroyRaster(puVar5);
            uVar20 = uVar1;
          }
          return false;
        }
        piVar14 = (int *)*DAT_1005b798;
        ppuStack_88 = (uint **)*piVar14;
        ppuVar11 = ppuStack_88 + piVar14[2];
        iVar4 = piVar14[2];
        do {
          ppuVar11 = ppuVar11 + -1;
          if (iVar4 == 0) {
            uVar1 = piVar14[1];
            if ((uint)piVar14[2] < uVar1) {
LAB_1003c6a9:
              *(uint **)(*piVar14 + piVar14[2] * 4) = unaff_EBX;
              piVar14[2] = piVar14[2] + 1;
            }
            else {
              iVar4 = (**(code **)(PTR_DAT_1005b69c + 0x354))(ppuStack_88,uVar1 * 4 + 0xa0,piVar6);
              if (iVar4 != 0) {
                *piVar14 = iVar4;
                piVar14[1] = uVar1 + 0x28;
                goto LAB_1003c6a9;
              }
            }
            uVar20 = uVar20 + 1;
            goto LAB_1003c5ae;
          }
          iVar4 = iVar4 + -1;
        } while (*ppuVar11 != unaff_EBX);
        uVar20 = uVar20 + 1;
      } while( true );
    }
  }
  else if (param_2 < 0x5343454f) {
    if (param_2 == 0x5343454e) {
      pppuVar8 = (uint ***)RwCreateScene();
      if (pppuVar8 == (uint ***)0x0) {
        return false;
      }
      DAT_1005b798 = FUN_10037030(DAT_1005b794);
      if (DAT_1005b798 != (int *)0x0) {
        piVar6 = FUN_10037030(DAT_1005b790);
        if (piVar6 != (int *)0x0) {
          iVar4 = (**(code **)(PTR_DAT_1005b69c + 0x34c))(0x28);
          *piVar6 = iVar4;
          if (iVar4 == 0) {
            if (piVar6 != (int *)0x0) {
              (**(code **)(PTR_DAT_1005b69c + 0x358))(0);
              FUN_10037010(DAT_1005b790,piVar6);
            }
            piVar6 = (int *)0x0;
          }
          else {
            piVar6[2] = 0;
            piVar6[1] = 10;
          }
        }
        *DAT_1005b798 = (int)piVar6;
        piVar6 = FUN_10037030(DAT_1005b790);
        if (piVar6 != (int *)0x0) {
          iVar4 = (**(code **)(PTR_DAT_1005b69c + 0x34c))(0x28);
          *piVar6 = iVar4;
          if (iVar4 == 0) {
            if (piVar6 != (int *)0x0) {
              (**(code **)(PTR_DAT_1005b69c + 0x358))(0);
              FUN_10037010(DAT_1005b790,piVar6);
            }
            piVar6 = (int *)0x0;
          }
          else {
            piVar6[2] = 0;
            piVar6[1] = 10;
          }
        }
        DAT_1005b798[1] = (int)piVar6;
        piVar6 = FUN_10037030(DAT_1005b790);
        if (piVar6 != (int *)0x0) {
          iVar4 = (**(code **)(PTR_DAT_1005b69c + 0x34c))(0x28);
          *piVar6 = iVar4;
          if (iVar4 == 0) {
            FUN_10039be0(piVar6);
            piVar6 = (int *)0x0;
          }
          else {
            piVar6[2] = 0;
            piVar6[1] = 10;
          }
        }
        DAT_1005b798[2] = (int)piVar6;
        piVar6 = FUN_10037030(DAT_1005b790);
        if (piVar6 != (int *)0x0) {
          iVar4 = (**(code **)(PTR_DAT_1005b69c + 0x34c))(0x28);
          *piVar6 = iVar4;
          if (iVar4 == 0) {
            FUN_10039be0(piVar6);
            piVar6 = (int *)0x0;
          }
          else {
            piVar6[2] = 0;
            piVar6[1] = 10;
          }
        }
        DAT_1005b798[3] = (int)piVar6;
        piVar6 = FUN_10039c20();
        DAT_1005b798[4] = (int)piVar6;
        DAT_1005b798[5] = 0;
        if ((((*DAT_1005b798 != 0) && (DAT_1005b798[1] != 0)) && (DAT_1005b798[2] != 0)) &&
           ((DAT_1005b798[3] != 0 && (DAT_1005b798[4] != 0)))) {
          do {
            bVar2 = RwReadStream((int *)param_1,&ppuStack_88,4);
            if (CONCAT31(extraout_var_19,bVar2) == 0) break;
            ppuStack_88 = (uint **)(((uint)ppuStack_88 & 0xff00 | (int)ppuStack_88 << 0x10) << 8 |
                                   ((uint)ppuStack_88 & 0xff0000 | (uint)ppuStack_88 >> 0x10) >> 8);
            if (ppuStack_88 == (uint **)0x52414c54) {
              bVar2 = true;
              goto LAB_1003abd7;
            }
            iVar4 = RwSkipStreamChunk((int *)param_1);
          } while (iVar4 != 0);
          bVar2 = false;
LAB_1003abd7:
          if (bVar2) {
            bVar2 = RwReadStreamChunk(param_1,0x52414c54,(int *)param_1);
            if (CONCAT31(extraout_var_20,bVar2) == 0) {
              bVar2 = false;
            }
            else {
              do {
                bVar2 = RwReadStream((int *)param_1,&ppuStack_8c,4);
                if (CONCAT31(extraout_var_21,bVar2) == 0) break;
                ppuStack_8c = (uint **)(((int)ppuStack_8c << 0x10 | (uint)ppuStack_8c & 0xff00) << 8
                                       | ((uint)ppuStack_8c >> 0x10 | (uint)ppuStack_8c & 0xff0000)
                                         >> 8);
                if (ppuStack_8c == (uint **)0x54454c54) {
                  bVar2 = true;
                  goto LAB_1003ac6b;
                }
                iVar4 = RwSkipStreamChunk((int *)param_1);
              } while (iVar4 != 0);
              bVar2 = false;
LAB_1003ac6b:
              if (bVar2) {
                bVar2 = RwReadStreamChunk(param_1,0x54454c54,(int *)param_1);
                if (CONCAT31(extraout_var_22,bVar2) == 0) {
                  bVar2 = false;
                }
                else {
                  do {
                    bVar2 = RwReadStream((int *)param_1,(undefined4 *)&stack0xffffff70,4);
                    if (CONCAT31(extraout_var_23,bVar2) == 0) break;
                    unaff_EBX = (uint *)(((uint)unaff_EBX & 0xff00 | (int)unaff_EBX << 0x10) << 8 |
                                        ((uint)unaff_EBX & 0xff0000 | (uint)unaff_EBX >> 0x10) >> 8)
                    ;
                    if (unaff_EBX == (uint *)0x4d414c54) {
                      bVar2 = true;
                      goto LAB_1003ad64;
                    }
                    bVar2 = RwReadStream((int *)param_1,&ppuStack_8c,4);
                    if (CONCAT31(extraout_var_24,bVar2) == 0) {
LAB_1003ad4f:
                      bVar2 = false;
                    }
                    else {
                      ppuStack_8c = (uint **)(((uint)ppuStack_8c & 0xff00 | (int)ppuStack_8c << 0x10
                                              ) << 8 | ((uint)ppuStack_8c & 0xff0000 |
                                                       (uint)ppuStack_8c >> 0x10) >> 8);
                      if (ppuStack_8c == (uint **)0x0) {
                        bVar2 = true;
                      }
                      else {
                        iVar4 = RwSeekStream((int *)param_1,(int)ppuStack_8c);
                        bVar2 = true;
                        if (iVar4 == 0) goto LAB_1003ad4f;
                      }
                    }
                  } while (bVar2);
                  bVar2 = false;
LAB_1003ad64:
                  if (bVar2) {
                    bVar3 = RwReadStreamChunk(param_1,0x4d414c54,(int *)param_1);
                    bVar2 = false;
                    if (CONCAT31(extraout_var_25,bVar3) != 0) {
                      bVar2 = true;
                      DAT_1005b798[5] = 1;
                    }
                  }
                  else {
                    FUN_1000cba0(0x5a);
                    bVar2 = false;
                  }
                }
              }
              else {
                FUN_1000cba0(0x5a);
                bVar2 = false;
              }
            }
          }
          else {
            FUN_1000cba0(0x5a);
            bVar2 = false;
          }
          if (!bVar2) {
            FUN_1003d550();
            return false;
          }
          do {
            bVar2 = RwReadStream((int *)param_1,&ppuStack_88,4);
            if (CONCAT31(extraout_var_26,bVar2) == 0) break;
            ppuStack_88 = (uint **)(((uint)ppuStack_88 & 0xff00 | (int)ppuStack_88 << 0x10) << 8 |
                                   ((uint)ppuStack_88 & 0xff0000 | (uint)ppuStack_88 >> 0x10) >> 8);
            if (ppuStack_88 == (uint **)0x53545254) {
              bVar2 = true;
              goto LAB_1003ae11;
            }
            iVar4 = RwSkipStreamChunk((int *)param_1);
          } while (iVar4 != 0);
          bVar2 = false;
LAB_1003ae11:
          if (!bVar2) {
            FUN_1003d550();
            FUN_1000cba0(0x5a);
            return false;
          }
          bVar2 = RwReadStreamChunk(param_1,0x53545254,(int *)(auStack_7c + 2));
          if (CONCAT31(extraout_var_27,bVar2) == 0) {
            return false;
          }
          puVar7 = auStack_7c;
          iVar4 = 1;
          do {
            puVar7 = puVar7 + 1;
            uVar20 = *puVar7;
            iVar4 = iVar4 + -1;
            *puVar7 = (uVar20 & 0xff00 | uVar20 << 0x10) << 8 |
                      (uVar20 & 0xff0000 | uVar20 >> 0x10) >> 8;
          } while (iVar4 != 0);
          uVar20 = 0;
          if (auStack_7c[1] != 0) {
LAB_1003ae93:
            do {
              bVar2 = RwReadStream((int *)param_1,&ppuStack_8c,4);
              if (CONCAT31(extraout_var_28,bVar2) == 0) {
LAB_1003aeec:
                bVar2 = false;
              }
              else {
                ppuStack_8c = (uint **)(((uint)ppuStack_8c & 0xff00 | (int)ppuStack_8c << 0x10) << 8
                                       | ((uint)ppuStack_8c & 0xff0000 | (uint)ppuStack_8c >> 0x10)
                                         >> 8);
                if (ppuStack_8c != (uint **)0x4c495445) {
                  iVar4 = RwSkipStreamChunk((int *)param_1);
                  if (iVar4 == 0) goto LAB_1003aeec;
                  goto LAB_1003ae93;
                }
                bVar2 = true;
              }
              if (!bVar2) {
                FUN_1003d550();
                RwDestroyScene(pppuVar8);
                FUN_1000cba0(0x5a);
                return false;
              }
              bVar2 = RwReadStreamChunk(param_1,0x4c495445,(int *)&uStack_84);
              if (CONCAT31(extraout_var_29,bVar2) == 0) {
                FUN_1003d550();
                RwDestroyScene(pppuVar8);
                return false;
              }
              uVar20 = uVar20 + 1;
              RwAddLightToScene((int)pppuVar8,ppuStack_88);
            } while (uVar20 < auStack_7c[0]);
          }
          do {
            bVar2 = RwReadStream((int *)param_1,&ppuStack_8c,4);
            if (CONCAT31(extraout_var_30,bVar2) == 0) break;
            ppuStack_8c = (uint **)(((uint)ppuStack_8c & 0xff00 | (int)ppuStack_8c << 0x10) << 8 |
                                   ((uint)ppuStack_8c & 0xff0000 | (uint)ppuStack_8c >> 0x10) >> 8);
            if (ppuStack_8c == (uint **)0x53545254) {
              bVar2 = true;
              goto LAB_1003afb6;
            }
            iVar4 = RwSkipStreamChunk((int *)param_1);
          } while (iVar4 != 0);
          bVar2 = false;
LAB_1003afb6:
          if (!bVar2) {
            FUN_1003d550();
            FUN_1000cba0(0x5a);
            return false;
          }
          bVar2 = RwReadStreamChunk(param_1,0x53545254,(int *)(auStack_7c + 1));
          if (CONCAT31(extraout_var_31,bVar2) == 0) {
            return false;
          }
          iVar4 = 1;
          puVar7 = auStack_7c;
          do {
            uVar20 = *puVar7;
            iVar4 = iVar4 + -1;
            *puVar7 = (uVar20 & 0xff00 | uVar20 << 0x10) << 8 |
                      (uVar20 & 0xff0000 | uVar20 >> 0x10) >> 8;
            puVar7 = puVar7 + 1;
          } while (iVar4 != 0);
          uVar20 = 0;
          do {
            if (auStack_7c[0] <= uVar20) {
              FUN_1003d550();
              *param_1 = pppuVar8;
              return true;
            }
            do {
              bVar2 = RwReadStream((int *)param_1,(undefined4 *)&stack0xffffff70,4);
              if (CONCAT31(extraout_var_32,bVar2) == 0) break;
              unaff_EBX = (uint *)(((uint)unaff_EBX & 0xff0000 | (uint)unaff_EBX >> 0x10) >> 8 |
                                  ((uint)unaff_EBX & 0xff00 | (int)unaff_EBX << 0x10) << 8);
              if (unaff_EBX == (uint *)0x41544f4d) {
                bVar2 = true;
                goto LAB_1003b093;
              }
              iVar4 = RwSkipStreamChunk((int *)param_1);
            } while (iVar4 != 0);
            bVar2 = false;
LAB_1003b093:
            if (!bVar2) {
              FUN_1003d550();
              RwDestroyScene(pppuVar8);
              FUN_1000cba0(0x5a);
              return false;
            }
            bVar2 = RwReadStreamChunk(param_1,0x41544f4d,(int *)&stack0xffffff6c);
            if (CONCAT31(extraout_var_33,bVar2) == 0) {
              FUN_1003d550();
              RwDestroyScene(pppuVar8);
              return false;
            }
            uVar20 = uVar20 + 1;
            RwAddClumpToScene((uint)pppuVar8,(uint)unaff_EDI);
          } while( true );
        }
        FUN_1003d550();
      }
      return false;
    }
    if (param_2 == 0x52454354) {
      do {
        bVar2 = RwReadStream((int *)param_1,&uStack_80,4);
        if (CONCAT31(extraout_var_83,bVar2) == 0) break;
        uStack_80 = (uStack_80 & 0xff00 | uStack_80 << 0x10) << 8 |
                    (uStack_80 & 0xff0000 | uStack_80 >> 0x10) >> 8;
        if (uStack_80 == 0x53545254) {
          bVar2 = true;
          goto LAB_1003caac;
        }
        iVar4 = RwSkipStreamChunk((int *)param_1);
      } while (iVar4 != 0);
      bVar2 = false;
LAB_1003caac:
      if (!bVar2) {
        FUN_1000cba0(0x5a);
        return false;
      }
      bVar2 = RwReadStreamChunk(param_1,0x53545254,(int *)(appuStack_6c + 2));
      if (CONCAT31(extraout_var_84,bVar2) != 0) {
        pppuVar8 = appuStack_6c;
        iVar4 = 4;
        do {
          pppuVar8 = pppuVar8 + 1;
          ppuVar11 = *pppuVar8;
          iVar4 = iVar4 + -1;
          *pppuVar8 = (uint **)(((uint)ppuVar11 & 0xff00 | (int)ppuVar11 << 0x10) << 8 |
                               ((uint)ppuVar11 & 0xff0000 | (uint)ppuVar11 >> 0x10) >> 8);
        } while (iVar4 != 0);
        ppuRam52454354 = appuStack_6c[1];
        ppuRam52454358 = appuStack_6c[2];
        ppuRam5245435c = ppuStack_60;
        ppuRam52454360 = ppuStack_5c;
        return true;
      }
      return false;
    }
  }
  else if (param_2 < 0x53545255) {
    if (param_2 == 0x53545254) {
      ppuVar9 = in_stack_00000010;
      if (ppuVar11 <= in_stack_00000010) {
        ppuVar9 = ppuVar11;
      }
      bVar2 = RwReadStream((int *)param_1,param_3,(uint)ppuVar9);
      if (CONCAT31(extraout_var_35,bVar2) != 0) {
        iVar4 = RwSeekStream((int *)param_1,(int)ppuVar11 - (int)in_stack_00000010);
        return (bool)('\x01' - (iVar4 == 0));
      }
      return false;
    }
    if (param_2 == 0x53544e47) {
      if (ppuVar11 == (uint **)0x0) {
        *param_3 = 0;
        return true;
      }
      puVar5 = (undefined4 *)(**(code **)(PTR_DAT_1005b69c + 0x34c))(ppuVar11);
      *param_3 = (int)puVar5;
      if (puVar5 != (undefined4 *)0x0) {
        bVar2 = RwReadStream((int *)param_1,puVar5,(uint)ppuStack_74);
        if (CONCAT31(extraout_var_34,bVar2) != 0) {
          return true;
        }
        return false;
      }
      FUN_1000cba0(3);
      return false;
    }
  }
  else if (param_2 < 0x54455856) {
    if (param_2 == 0x54455855) {
      do {
        bVar2 = RwReadStream((int *)param_1,&uStack_80,4);
        if (CONCAT31(extraout_var_90,bVar2) == 0) break;
        uStack_80 = (uStack_80 & 0xff00 | uStack_80 << 0x10) << 8 |
                    (uStack_80 & 0xff0000 | uStack_80 >> 0x10) >> 8;
        if (uStack_80 == 0x53545254) {
          bVar2 = true;
          goto LAB_1003cf7c;
        }
        iVar4 = RwSkipStreamChunk((int *)param_1);
      } while (iVar4 != 0);
      bVar2 = false;
LAB_1003cf7c:
      if (!bVar2) {
        FUN_1000cba0(0x5a);
        return false;
      }
      bVar2 = RwReadStreamChunk(param_1,0x53545254,(int *)(appuStack_6c + 2));
      if (CONCAT31(extraout_var_91,bVar2) == 0) {
        return false;
      }
      pppuVar8 = appuStack_6c;
      iVar4 = 5;
      do {
        pppuVar8 = pppuVar8 + 1;
        ppuVar11 = *pppuVar8;
        iVar4 = iVar4 + -1;
        *pppuVar8 = (uint **)(((uint)ppuVar11 & 0xff00 | (int)ppuVar11 << 0x10) << 8 |
                             ((uint)ppuVar11 & 0xff0000 | (uint)ppuVar11 >> 0x10) >> 8);
      } while (iVar4 != 0);
      do {
        bVar2 = RwReadStream((int *)param_1,&uStack_84,4);
        if (CONCAT31(extraout_var_92,bVar2) == 0) break;
        uStack_84 = (uStack_84 & 0xff00 | uStack_84 << 0x10) << 8 |
                    (uStack_84 & 0xff0000 | uStack_84 >> 0x10) >> 8;
        if (uStack_84 == 0x53544e47) {
          bVar2 = true;
          goto LAB_1003d045;
        }
        iVar4 = RwSkipStreamChunk((int *)param_1);
      } while (iVar4 != 0);
      bVar2 = false;
LAB_1003d045:
      if (!bVar2) {
        FUN_1000cba0(0x5a);
        return false;
      }
      bVar2 = RwReadStreamChunk(param_1,0x53544e47,(int *)&ppuStack_88);
      if (CONCAT31(extraout_var_93,bVar2) == 0) {
        return false;
      }
      if (appuStack_6c[0] == (uint **)0x0) {
        unaff_ESI = (int *)0x0;
      }
      else {
        do {
          bVar2 = RwReadStream((int *)param_1,&ppuStack_88,4);
          if (CONCAT31(extraout_var_94,bVar2) == 0) break;
          ppuStack_88 = (uint **)(((uint)ppuStack_88 & 0xff00 | (int)ppuStack_88 << 0x10) << 8 |
                                 ((uint)ppuStack_88 & 0xff0000 | (uint)ppuStack_88 >> 0x10) >> 8);
          if (ppuStack_88 == (uint **)0x52415354) {
            bVar2 = true;
            goto LAB_1003d18e;
          }
          iVar4 = RwSkipStreamChunk((int *)param_1);
        } while (iVar4 != 0);
        bVar2 = false;
LAB_1003d18e:
        if (!bVar2) {
          FUN_1000cba0(0x5a);
          return false;
        }
        bVar2 = RwReadStreamChunk(param_1,0x52415354,(int *)&stack0xffffff6c);
        if (CONCAT31(extraout_var_95,bVar2) == 0) {
          return false;
        }
      }
      if (appuStack_6c[0] == (uint **)0x0) {
        unaff_ESI = (int *)0x0;
      }
      else {
        do {
          bVar2 = RwReadStream((int *)param_1,&ppuStack_8c,4);
          if (CONCAT31(extraout_var_96,bVar2) == 0) break;
          ppuStack_8c = (uint **)(((uint)ppuStack_8c & 0xff00 | (int)ppuStack_8c << 0x10) << 8 |
                                 ((uint)ppuStack_8c & 0xff0000 | (uint)ppuStack_8c >> 0x10) >> 8);
          if (ppuStack_8c == (uint **)0x52415354) {
            bVar2 = true;
            goto LAB_1003d224;
          }
          iVar4 = RwSkipStreamChunk((int *)param_1);
        } while (iVar4 != 0);
        bVar2 = false;
LAB_1003d224:
        if (!bVar2) {
          FUN_1000cba0(0x5a);
          return false;
        }
        bVar2 = RwReadStreamChunk(param_1,0x52415354,(int *)&stack0xffffff6c);
        if (CONCAT31(extraout_var_97,bVar2) == 0) {
          return false;
        }
      }
      if ((unaff_EBX != (uint *)0x0) && (((uint)param_1 & 8) == 0)) {
        piVar6 = (int *)FUN_100184d0((int)unaff_EBX);
        if (piVar6 == (int *)0x0) {
          puVar5 = FUN_10021270((char *)unaff_EBX);
          if (puVar5 != (undefined4 *)0x0) {
            piVar6 = RwGetNamedTexture((char *)unaff_EBX);
          }
          if (piVar6 == (int *)0x0) goto LAB_1003d25a;
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
        *unaff_retaddr = (int)piVar6;
        return true;
      }
LAB_1003d25a:
      if (unaff_EDI == (undefined4 *)0x0) {
        FUN_1000cba0(0x5e);
        return false;
      }
      piVar6 = FUN_10017400();
      if (piVar6 == (int *)0x0) {
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
      iVar4 = RwSetTextureRaster((int)piVar6,(int)unaff_EDI);
      if (iVar4 == 0) {
        if (unaff_EBX != (uint *)0x0) {
          (**(code **)(PTR_DAT_1005b69c + 0x358))(unaff_EBX);
        }
        if (unaff_EDI != (undefined4 *)0x0) {
          RwDestroyRaster(unaff_EDI);
        }
        if (unaff_ESI != (int *)0x0) {
          RwDestroyRaster(unaff_ESI);
        }
        if (piVar6 != (int *)0x0) {
          RwDestroyTexture(piVar6);
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
          iVar4 = RwSetTextureMipmapRaster((int)piVar6,(int)unaff_ESI);
          if (iVar4 == 0) {
            if (unaff_EBX != (uint *)0x0) {
              (**(code **)(PTR_DAT_1005b69c + 0x358))(unaff_EBX);
            }
            if (unaff_EDI != (undefined4 *)0x0) {
              RwDestroyRaster(unaff_EDI);
            }
            if (unaff_ESI != (int *)0x0) {
              RwDestroyRaster(unaff_ESI);
            }
            if (piVar6 != (int *)0x0) {
              RwDestroyTexture(piVar6);
            }
            return false;
          }
        }
      }
      if ((unaff_EBX != (uint *)0x0) && (iVar4 = FUN_100184d0((int)unaff_EBX), iVar4 != 0)) {
        (**(code **)(PTR_DAT_1005b69c + 0x358))(unaff_EBX);
        unaff_EBX = (uint *)0x0;
      }
      piVar14 = RwAddTextureToDict((char *)unaff_EBX,piVar6);
      if (piVar14 != (int *)0x0) {
        if (unaff_EBX != (uint *)0x0) {
          (**(code **)(PTR_DAT_1005b69c + 0x358))(unaff_EBX);
        }
        RwSetTextureFrame((int)piVar6,(int)appuStack_6c[2]);
        RwSetTextureFrame((int)piVar6,(int)appuStack_6c[2]);
        RwSetTextureFrameStep((int)piVar6,(int)ppuStack_60);
        *unaff_retaddr = (int)piVar6;
        return true;
      }
      if (unaff_EDI != (undefined4 *)0x0) {
        RwDestroyRaster(unaff_EDI);
      }
      if (unaff_ESI != (int *)0x0) {
        RwDestroyRaster(unaff_ESI);
      }
      if (piVar6 != (int *)0x0) {
        RwDestroyTexture(piVar6);
      }
      if (unaff_EBX != (uint *)0x0) {
        (**(code **)(PTR_DAT_1005b69c + 0x358))(unaff_EBX);
      }
      return false;
    }
    if (param_2 == 0x54454c54) {
      do {
        bVar2 = RwReadStream((int *)param_1,&uStack_80,4);
        if (CONCAT31(extraout_var_85,bVar2) == 0) break;
        uStack_80 = (uStack_80 & 0xff00 | uStack_80 << 0x10) << 8 |
                    (uStack_80 & 0xff0000 | uStack_80 >> 0x10) >> 8;
        if (uStack_80 == 0x53545254) {
          bVar2 = true;
          goto LAB_1003cb9f;
        }
        iVar4 = RwSkipStreamChunk((int *)param_1);
      } while (iVar4 != 0);
      bVar2 = false;
LAB_1003cb9f:
      if (!bVar2) {
        FUN_1000cba0(0x5a);
        return false;
      }
      bVar2 = RwReadStreamChunk(param_1,0x53545254,(int *)(auStack_7c + 3));
      if (CONCAT31(extraout_var_86,bVar2) == 0) {
        return false;
      }
      iVar4 = 3;
      puVar7 = auStack_7c + 2;
      do {
        uVar20 = *puVar7;
        iVar4 = iVar4 + -1;
        *puVar7 = (uVar20 & 0xff00 | uVar20 << 0x10) << 8 |
                  (uVar20 & 0xff0000 | uVar20 >> 0x10) >> 8;
        puVar7 = puVar7 + 1;
      } while (iVar4 != 0);
      ppuStack_8c = (uint **)0x0;
      if (ppuStack_74 == (uint **)0x0) {
        return true;
      }
      do {
        bVar2 = RwReadStream((int *)param_1,appuStack_6c + 1,0x14);
        if (CONCAT31(extraout_var_87,bVar2) == 0) {
          return false;
        }
        pppuVar8 = appuStack_6c;
        iVar4 = 5;
        do {
          pppuVar8 = pppuVar8 + 1;
          ppuVar11 = *pppuVar8;
          iVar4 = iVar4 + -1;
          *pppuVar8 = (uint **)(((uint)ppuVar11 & 0xff00 | (int)ppuVar11 << 0x10) << 8 |
                               ((uint)ppuVar11 & 0xff0000 | (uint)ppuVar11 >> 0x10) >> 8);
        } while (iVar4 != 0);
        if (uStack_70 < 0x14) {
          RwSeekStream((int *)param_1,0x14 - uStack_70);
        }
        do {
          bVar2 = RwReadStream((int *)param_1,&uStack_84,4);
          if (CONCAT31(extraout_var_88,bVar2) == 0) break;
          uStack_84 = (uStack_84 & 0xff00 | uStack_84 << 0x10) << 8 |
                      (uStack_84 & 0xff0000 | uStack_84 >> 0x10) >> 8;
          if (uStack_84 == 0x53544e47) {
            bVar2 = true;
            goto LAB_1003cce3;
          }
          iVar4 = RwSkipStreamChunk((int *)param_1);
        } while (iVar4 != 0);
        bVar2 = false;
LAB_1003cce3:
        if (!bVar2) {
          FUN_1000cba0(0x5a);
          return false;
        }
        piVar6 = param_3;
        bVar2 = RwReadStreamChunk(param_1,0x53544e47,(int *)&stack0xffffff70);
        if (CONCAT31(extraout_var_89,bVar2) == 0) {
          return false;
        }
        piVar14 = (int *)0x0;
        if (appuStack_6c[0] == (uint **)0x0) {
          if (unaff_ESI != (int *)0x0) {
            piVar14 = (int *)FUN_100184d0((int)unaff_ESI);
            if (piVar14 != (int *)0x0) goto LAB_1003ce2a;
            puVar5 = FUN_10021270((char *)unaff_ESI);
            if (puVar5 != (undefined4 *)0x0) {
              piVar14 = RwGetNamedTexture((char *)unaff_ESI);
            }
          }
          if (piVar14 == (int *)0x0) {
            if (unaff_ESI != (int *)0x0) {
              (**(code **)(PTR_DAT_1005b69c + 0x358))(unaff_ESI,piVar6);
            }
            FUN_1000cba0(0x5e);
            return false;
          }
        }
        else {
          if (unaff_ESI != (int *)0x0) {
            piVar14 = (int *)FUN_100184d0((int)unaff_ESI);
          }
          if (piVar14 == (int *)0x0) {
            piVar14 = FUN_10017400();
            if (((uint **)((int *)*DAT_1005b798)[2] < appuStack_6c[0]) ||
               (appuStack_6c[0] == (uint **)0x0)) {
              iVar4 = 0;
            }
            else {
              iVar4 = *(int *)(*(int *)*DAT_1005b798 + -4 + (int)appuStack_6c[0] * 4);
            }
            iVar4 = RwSetTextureRaster((int)piVar14,iVar4);
            if (iVar4 == 0) {
              RwDestroyTexture(piVar14);
              return false;
            }
            if (appuStack_6c[1] != (uint **)0x0) {
              if (((uint **)((int *)*DAT_1005b798)[2] < appuStack_6c[1]) ||
                 (appuStack_6c[1] == (uint **)0x0)) {
                iVar4 = 0;
              }
              else {
                iVar4 = *(int *)(*(int *)*DAT_1005b798 + -4 + (int)appuStack_6c[1] * 4);
              }
              iVar4 = RwSetTextureMipmapRaster((int)piVar14,iVar4);
              if (iVar4 == 0) {
                RwDestroyTexture(piVar14);
                return false;
              }
            }
            iVar4 = FUN_100184d0((int)unaff_ESI);
            if (iVar4 != 0) {
              (**(code **)(PTR_DAT_1005b69c + 0x358))(unaff_ESI);
              unaff_ESI = (int *)0x0;
            }
            piVar6 = RwAddTextureToDict((char *)unaff_ESI,piVar14);
            if (piVar6 == (int *)0x0) {
              return false;
            }
          }
        }
LAB_1003ce2a:
        if (unaff_ESI != (int *)0x0) {
          (**(code **)(PTR_DAT_1005b69c + 0x358))(unaff_ESI);
        }
        piVar15 = (int *)DAT_1005b798[1];
        piVar6 = (int *)(*piVar15 + piVar15[2] * 4);
        iVar4 = piVar15[2];
        do {
          piVar6 = piVar6 + -1;
          if (iVar4 == 0) {
            uVar20 = piVar15[1];
            if (uVar20 <= (uint)piVar15[2]) {
              iVar4 = (**(code **)(PTR_DAT_1005b69c + 0x354))(*piVar15,uVar20 * 4 + 0xa0);
              if (iVar4 == 0) break;
              *piVar15 = iVar4;
              piVar15[1] = uVar20 + 0x28;
            }
            *(int **)(*piVar15 + piVar15[2] * 4) = piVar14;
            piVar15[2] = piVar15[2] + 1;
            break;
          }
          iVar4 = iVar4 + -1;
        } while ((int *)*piVar6 != piVar14);
        ppuStack_8c = (uint **)((int)ppuStack_8c + 1);
        if (ppuStack_74 <= ppuStack_8c) {
          return true;
        }
      } while( true );
    }
  }
  else {
    if (param_2 == 0x56334420) {
      do {
        bVar2 = RwReadStream((int *)param_1,&uStack_80,4);
        if (CONCAT31(extraout_var_98,bVar2) == 0) break;
        uStack_80 = (uStack_80 & 0xff00 | uStack_80 << 0x10) << 8 |
                    (uStack_80 & 0xff0000 | uStack_80 >> 0x10) >> 8;
        if (uStack_80 == 0x53545254) {
          bVar2 = true;
          goto LAB_1003d4af;
        }
        iVar4 = RwSkipStreamChunk((int *)param_1);
      } while (iVar4 != 0);
      bVar2 = false;
LAB_1003d4af:
      if (!bVar2) {
        FUN_1000cba0(0x5a);
        return false;
      }
      bVar2 = RwReadStreamChunk(param_1,0x53545254,(int *)(appuStack_6c + 2));
      if (CONCAT31(extraout_var_99,bVar2) != 0) {
        pppuVar8 = appuStack_6c;
        iVar4 = 3;
        do {
          pppuVar8 = pppuVar8 + 1;
          ppuVar11 = *pppuVar8;
          iVar4 = iVar4 + -1;
          *pppuVar8 = (uint **)(((uint)ppuVar11 & 0xff00 | (int)ppuVar11 << 0x10) << 8 |
                               ((uint)ppuVar11 & 0xff0000 | (uint)ppuVar11 >> 0x10) >> 8);
        } while (iVar4 != 0);
        ppuRam56334420 = appuStack_6c[1];
        ppuRam56334424 = appuStack_6c[2];
        ppuRam56334428 = ppuStack_60;
        return true;
      }
      return false;
    }
    if (param_2 == 0x564c5354) {
      do {
        bVar2 = RwReadStream((int *)param_1,&uStack_80,4);
        if (CONCAT31(extraout_var_36,bVar2) == 0) break;
        uStack_80 = (uStack_80 & 0xff00 | uStack_80 << 0x10) << 8 |
                    (uStack_80 & 0xff0000 | uStack_80 >> 0x10) >> 8;
        if (uStack_80 == 0x53545254) {
          bVar2 = true;
          goto LAB_1003b21f;
        }
        iVar4 = RwSkipStreamChunk((int *)param_1);
      } while (iVar4 != 0);
      bVar2 = false;
LAB_1003b21f:
      if (!bVar2) {
        FUN_1000cba0(0x5a);
        return false;
      }
      bVar2 = RwReadStreamChunk(param_1,0x53545254,(int *)(auStack_7c + 3));
      if (CONCAT31(extraout_var_37,bVar2) != 0) {
        iVar4 = 3;
        puVar7 = auStack_7c + 2;
        do {
          uVar20 = *puVar7;
          iVar4 = iVar4 + -1;
          *puVar7 = (uVar20 & 0xff00 | uVar20 << 0x10) << 8 |
                    (uVar20 & 0xff0000 | uVar20 >> 0x10) >> 8;
          puVar7 = puVar7 + 1;
        } while (iVar4 != 0);
        piVar6 = FUN_10041cb0((int)ppuStack_74);
        if (piVar6 != (int *)0x0) {
          *piRam564c53dc = 0;
          FUN_10041d80(piRam564c53dc);
          piRam564c53dc = piVar6;
          *piVar6 = 0x564c5354;
          piVar6[2] = (int)ppuStack_74;
          iVar4 = (((int)appuStack_6c[0] << 0x1d) >> 0x1f & 0xcU) + ((uint)appuStack_6c[0] & 2) * 4
                  + 0xc + (((int)appuStack_6c[0] << 0x1f) >> 0x1f & 0xcU);
          if (iVar4 < (int)uStack_70) {
            uStack_84 = uStack_70 - iVar4;
          }
          else {
            uStack_84 = 0;
          }
          ppuStack_8c = (uint **)0x0;
          if (ppuStack_74 == (uint **)0x0) {
            return true;
          }
          pbVar12 = (byte *)(piVar6 + 0x15);
          do {
            *pbVar12 = 0;
            bVar2 = RwReadStream((int *)param_1,appuStack_6c + 1,0xc);
            if (CONCAT31(extraout_var_38,bVar2) == 0) {
              return false;
            }
            pppuVar8 = appuStack_6c;
            iVar4 = 3;
            do {
              pppuVar8 = pppuVar8 + 1;
              ppuVar11 = *pppuVar8;
              iVar4 = iVar4 + -1;
              *pppuVar8 = (uint **)(((uint)ppuVar11 & 0xff00 | (int)ppuVar11 << 0x10) << 8 |
                                   ((uint)ppuVar11 & 0xff0000 | (uint)ppuVar11 >> 0x10) >> 8);
            } while (iVar4 != 0);
            *(uint ***)(pbVar12 + -0x48) = appuStack_6c[1];
            *(uint ***)(pbVar12 + -0x44) = appuStack_6c[2];
            *(uint ***)(pbVar12 + -0x40) = ppuStack_60;
            if (((uint)appuStack_6c[0] & 1) != 0) {
              bVar2 = RwReadStream((int *)param_1,appuStack_6c + 1,0xc);
              if (CONCAT31(extraout_var_39,bVar2) == 0) {
                return false;
              }
              pppuVar8 = appuStack_6c;
              iVar4 = 3;
              do {
                pppuVar8 = pppuVar8 + 1;
                ppuVar11 = *pppuVar8;
                iVar4 = iVar4 + -1;
                *pppuVar8 = (uint **)(((uint)ppuVar11 & 0xff00 | (int)ppuVar11 << 0x10) << 8 |
                                     ((uint)ppuVar11 & 0xff0000 | (uint)ppuVar11 >> 0x10) >> 8);
              } while (iVar4 != 0);
              *(uint ***)(pbVar12 + 4) = appuStack_6c[1];
              *(uint ***)(pbVar12 + 8) = appuStack_6c[2];
              *(uint ***)(pbVar12 + 0xc) = ppuStack_60;
              *pbVar12 = *pbVar12 | 0x40;
            }
            if (((uint)appuStack_6c[0] & 2) != 0) {
              bVar2 = RwReadStream((int *)param_1,appuStack_6c + 1,8);
              if (CONCAT31(extraout_var_40,bVar2) == 0) {
                return false;
              }
              pppuVar8 = appuStack_6c;
              iVar4 = 2;
              do {
                pppuVar8 = pppuVar8 + 1;
                ppuVar11 = *pppuVar8;
                iVar4 = iVar4 + -1;
                *pppuVar8 = (uint **)(((uint)ppuVar11 & 0xff00 | (int)ppuVar11 << 0x10) << 8 |
                                     ((uint)ppuVar11 & 0xff0000 | (uint)ppuVar11 >> 0x10) >> 8);
              } while (iVar4 != 0);
              lVar18 = __ftol();
              *(int *)(pbVar12 + 0x1c) = (int)lVar18;
              lVar18 = __ftol();
              *(int *)(pbVar12 + 0x20) = (int)lVar18;
            }
            if (((uint)appuStack_6c[0] & 4) != 0) {
              bVar2 = RwReadStream((int *)param_1,appuStack_6c + 1,0xc);
              if (CONCAT31(extraout_var_41,bVar2) == 0) {
                return false;
              }
              pppuVar8 = appuStack_6c;
              iVar4 = 3;
              do {
                pppuVar8 = pppuVar8 + 1;
                ppuVar11 = *pppuVar8;
                iVar4 = iVar4 + -1;
                *pppuVar8 = (uint **)(((uint)ppuVar11 & 0xff00 | (int)ppuVar11 << 0x10) << 8 |
                                     ((uint)ppuVar11 & 0xff0000 | (uint)ppuVar11 >> 0x10) >> 8);
              } while (iVar4 != 0);
              lVar18 = __ftol();
              *(int *)(pbVar12 + 0x10) = (int)lVar18;
              lVar18 = __ftol();
              *(int *)(pbVar12 + 0x14) = (int)lVar18;
              lVar18 = __ftol();
              *(int *)(pbVar12 + 0x18) = (int)lVar18;
            }
            pbVar12[0x28] = 0;
            pbVar12[0x29] = 0;
            pbVar12[0x2a] = 0;
            pbVar12[0x2b] = 0;
            pbVar12[0x26] = 0;
            pbVar12[0x27] = 0;
            pbVar12[0x24] = 0;
            pbVar12[0x25] = 0;
            if (uStack_84 != 0) {
              RwSeekStream((int *)param_1,uStack_84);
            }
            pbVar12 = pbVar12 + 0x74;
            ppuStack_8c = (uint **)((int)ppuStack_8c + 1);
          } while (ppuStack_8c < ppuStack_74);
          return true;
        }
        return false;
      }
      return false;
    }
  }
  bVar2 = RwReadStream((int *)param_1,&uStack_80,4);
  if (CONCAT31(extraout_var_00,bVar2) != 0) {
    uStack_80 = (uStack_80 >> 0x10 | uStack_80 & 0xff0000) >> 8 |
                (uStack_80 << 0x10 | uStack_80 & 0xff00) << 8;
    if (uStack_80 == 0) {
      bVar2 = true;
      goto LAB_1003a028;
    }
    iVar4 = RwSeekStream((int *)param_1,uStack_80);
    bVar2 = true;
    if (iVar4 != 0) goto LAB_1003a028;
  }
  bVar2 = false;
LAB_1003a028:
  if (!bVar2) {
    FUN_1000cba0(0x59);
  }
  return false;
}


