// 10034e20 FUN_10034e20 [Global]
// programa: RWL21.DLL

undefined4 FUN_10034e20(FILE *param_1,int param_2,uint *param_3,uint *param_4)

{
  float fVar1;
  int iVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  uint *puVar14;
  uint uVar15;
  char *pcVar16;
  uint uVar17;
  float10 fVar18;
  float local_118;
  undefined4 local_110;
  undefined4 uStack_10c;
  uint local_104;
  uint local_100;
  float local_ec;
  float local_e8;
  float local_e4;
  int local_e0;
  int local_dc;
  int *local_d8;
  float local_d4;
  float local_d0;
  float local_cc;
  float local_c8;
  float local_c4;
  float local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  float local_b0;
  float local_ac;
  float local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  float local_8c;
  float local_88;
  float local_84;
  char local_80 [128];
  uint uVar9;
  
  local_118 = 0.0;
  local_e0 = 0;
  local_dc = 0;
  local_d8 = (int *)0x0;
  local_104 = 0;
  local_100 = 0;
  local_cc = 0.0;
  local_d0 = 0.0;
  local_d4 = 0.0;
  local_9c = 0;
  local_a0 = 0;
  local_a4 = 0;
  local_90 = 0;
  local_94 = 0;
  local_98 = 0;
  RwGetMaterialColor((int)param_3,&local_ec);
  RwGetMaterialAmbientRGB((int)param_3,&local_c8);
  RwGetMaterialDiffuseRGB((int)param_3,&local_bc);
  RwGetMaterialSpecularRGB((int)param_3,&local_b0);
  iVar6 = RwGetMaterialLightSampling(param_3);
  iVar7 = RwGetMaterialGeometrySampling(param_3);
  piVar8 = (int *)RwGetMaterialTexture((int)param_3);
  bVar3 = RwGetMaterialTextureModes((int)param_3);
  uVar15 = CONCAT31(extraout_var,bVar3);
  bVar4 = RwGetMaterialModes((int)param_3);
  uVar9 = CONCAT31(extraout_var_00,bVar4);
  fVar18 = RwGetMaterialOpacity((int)param_3);
  fVar1 = (float)fVar18;
  iVar11 = param_2;
  iVar12 = param_2;
  iVar2 = param_2;
  if (param_4 == (uint *)0x0) {
joined_r0x10034fb5:
    for (; iVar11 != 0; iVar11 = iVar11 + -1) {
      iVar10 = _fputc(0x20,param_1);
      if (iVar10 == -1) {
        FUN_1000cba0(6);
        return 0;
      }
    }
    iVar11 = _fprintf(param_1,s_Color__f__f__f_1005b274,(double)local_ec,(double)local_e8,
                      (double)local_e4);
    if (iVar11 == -1) {
      FUN_1000cba0(6);
      return 0;
    }
    if (param_4 != (uint *)0x0) {
      iVar11 = RwSetMaterialColor((int)param_4,(uint)local_ec,(uint)local_e8,(uint)local_e4);
      if (iVar11 == 0) {
        return 0;
      }
      goto LAB_10035057;
    }
joined_r0x10035090:
    for (; iVar12 != 0; iVar12 = iVar12 + -1) {
      iVar11 = _fputc(0x20,param_1);
      if (iVar11 == -1) {
        FUN_1000cba0(6);
        return 0;
      }
    }
    uStack_10c = (undefined4)((ulonglong)(double)local_c4 >> 0x20);
    local_110 = SUB84((double)local_c4,0);
    iVar11 = _fprintf(param_1,s_Ambient__f__f__f_1005b260,(double)local_c8,local_110,uStack_10c,
                      local_110);
    if (iVar11 == -1) {
      FUN_1000cba0(6);
      return 0;
    }
    if ((param_4 != (uint *)0x0) &&
       (iVar11 = RwSetMaterialAmbientRGBStruct((int)param_4,(uint *)&local_c8), iVar11 == 0)) {
      return 0;
    }
  }
  else {
    RwGetMaterialColor((int)param_4,&local_8c);
    RwGetMaterialAmbientRGB((int)param_4,&local_d4);
    RwGetMaterialDiffuseRGB((int)param_4,&local_a4);
    RwGetMaterialSpecularRGB((int)param_4,&local_98);
    local_e0 = RwGetMaterialLightSampling(param_4);
    local_dc = RwGetMaterialGeometrySampling(param_4);
    local_d8 = (int *)RwGetMaterialTexture((int)param_4);
    bVar5 = RwGetMaterialTextureModes((int)param_4);
    local_104 = CONCAT31(extraout_var_01,bVar5);
    bVar5 = RwGetMaterialModes((int)param_4);
    local_100 = CONCAT31(extraout_var_02,bVar5);
    fVar18 = RwGetMaterialOpacity((int)param_4);
    local_118 = (float)fVar18;
    if (((local_ec != local_8c) || (local_e8 != local_88)) || (local_e4 != local_84))
    goto joined_r0x10034fb5;
LAB_10035057:
    if (((param_4 == (uint *)0x0) || (local_c8 != local_d4)) ||
       ((local_c4 != local_d0 || (local_c0 != local_cc)))) goto joined_r0x10035090;
  }
  for (; iVar2 != 0; iVar2 = iVar2 + -1) {
    iVar11 = _fputc(0x20,param_1);
    if (iVar11 == -1) {
      FUN_1000cba0(6);
      return 0;
    }
  }
  iVar11 = _fprintf(param_1,s_Diffuse__f__f__f_1005b24c,(double)local_bc,(double)local_b8,
                    (double)local_b4);
  if (iVar11 == -1) {
    FUN_1000cba0(6);
    return 0;
  }
  iVar11 = param_2;
  if ((param_4 != (uint *)0x0) &&
     (iVar12 = RwSetMaterialDiffuseRGBStruct((int)param_4,(uint *)&local_bc), iVar12 == 0)) {
    return 0;
  }
  for (; iVar11 != 0; iVar11 = iVar11 + -1) {
    iVar12 = _fputc(0x20,param_1);
    if (iVar12 == -1) {
      FUN_1000cba0(6);
      return 0;
    }
  }
  iVar11 = _fprintf(param_1,s_Specular__f__f__f_1005b238,(double)local_b0,(double)local_ac,
                    (double)local_a8);
  if (iVar11 == -1) {
    FUN_1000cba0(6);
    return 0;
  }
  iVar11 = param_2;
  iVar12 = param_2;
  iVar2 = param_2;
  iVar10 = param_2;
  if (param_4 == (uint *)0x0) {
joined_r0x1003524d:
    for (; iVar11 != 0; iVar11 = iVar11 + -1) {
      iVar13 = _fputc(0x20,param_1);
      if (iVar13 == -1) {
        FUN_1000cba0(6);
        return 0;
      }
    }
    iVar11 = _fprintf(param_1,s_Opacity__f_1005b22c,(double)fVar1);
    if (iVar11 == -1) {
      FUN_1000cba0(6);
      return 0;
    }
    if (param_4 != (uint *)0x0) {
      puVar14 = RwSetMaterialOpacity(param_4,(uint)fVar1);
      if (puVar14 == (uint *)0x0) {
        return 0;
      }
      goto LAB_100352c0;
    }
joined_r0x100352d8:
    for (; iVar12 != 0; iVar12 = iVar12 + -1) {
      iVar11 = _fputc(0x20,param_1);
      if (iVar11 == -1) {
        FUN_1000cba0(6);
        return 0;
      }
    }
    if ((iVar6 != 1) && (iVar6 != 2)) {
      FUN_1000cba0(0x1d);
      return 0;
    }
    iVar11 = _fprintf(param_1,s_LightSampling__s_1005b208);
    if (iVar11 == -1) {
      FUN_1000cba0(6);
      return 0;
    }
    if (param_4 != (uint *)0x0) {
      puVar14 = RwSetMaterialLightSampling(param_4,iVar6);
      if (puVar14 == (uint *)0x0) {
        return 0;
      }
      goto LAB_1003536d;
    }
joined_r0x10035385:
    for (; iVar2 != 0; iVar2 = iVar2 + -1) {
      iVar11 = _fputc(0x20,param_1);
      if (iVar11 == -1) {
        FUN_1000cba0(6);
        return 0;
      }
    }
    if (((iVar7 != 1) && (iVar7 != 2)) && (iVar7 != 4)) {
      FUN_1000cba0(0x1b);
      return 0;
    }
    iVar11 = _fprintf(param_1,s_GeometrySampling__s_1005b1d0);
    if (iVar11 == -1) {
      FUN_1000cba0(6);
      return 0;
    }
    if (param_4 != (uint *)0x0) {
      puVar14 = RwSetMaterialGeometrySampling(param_4,iVar7);
      if (puVar14 == (uint *)0x0) {
        return 0;
      }
      goto LAB_10035426;
    }
  }
  else {
    iVar13 = RwSetMaterialSpecularRGBStruct((int)param_4,(uint *)&local_b0);
    if (iVar13 == 0) {
      return 0;
    }
    if ((param_4 == (uint *)0x0) || (fVar1 != local_118)) goto joined_r0x1003524d;
LAB_100352c0:
    if ((param_4 == (uint *)0x0) || (local_e0 != iVar6)) goto joined_r0x100352d8;
LAB_1003536d:
    if ((param_4 == (uint *)0x0) || (local_dc != iVar7)) goto joined_r0x10035385;
LAB_10035426:
    if (param_4 != (uint *)0x0) {
      if (local_104 != uVar15) {
        uVar17 = local_104 & (local_104 ^ uVar15);
        iVar11 = param_2;
        if (uVar17 != 0) {
          for (; iVar11 != 0; iVar11 = iVar11 + -1) {
            iVar12 = _fputc(0x20,param_1);
            if (iVar12 == -1) {
              FUN_1000cba0(6);
              return 0;
            }
          }
          iVar11 = _fprintf(param_1,s_RemoveTextureMode_1005b174);
          if (iVar11 == -1) {
            FUN_1000cba0(6);
            return 0;
          }
          iVar11 = 1;
          if ((uVar17 & 1) != 0) {
            iVar11 = _fprintf(param_1,&DAT_1005b2b8);
          }
          if (iVar11 == 0) {
LAB_10035703:
            if (iVar11 == 0) {
              return 0;
            }
            if ((uVar17 & 0x10) != 0) {
              iVar11 = _fprintf(param_1,s_Trilinear_1005b294);
            }
          }
          else {
            if ((uVar17 & 2) != 0) {
              iVar11 = _fprintf(param_1,s_Foreshorten_1005b2a8);
            }
            if (iVar11 != 0) {
              if ((uVar17 & 4) != 0) {
                iVar11 = _fprintf(param_1,s_Filter_1005b2a0);
              }
              goto LAB_10035703;
            }
          }
          if (iVar11 == 0) {
            return 0;
          }
          iVar11 = _fprintf(param_1,&DAT_1005b120);
          if (iVar11 == -1) {
            FUN_1000cba0(6);
            return 0;
          }
        }
        uVar17 = uVar15 & (local_104 ^ uVar15);
        iVar11 = param_2;
        if (uVar17 != 0) {
          for (; iVar11 != 0; iVar11 = iVar11 + -1) {
            iVar12 = _fputc(0x20,param_1);
            if (iVar12 == -1) {
              FUN_1000cba0(6);
              return 0;
            }
          }
          iVar11 = _fprintf(param_1,s_AddTextureMode_1005b164);
          if (iVar11 == -1) {
            FUN_1000cba0(6);
            return 0;
          }
          iVar11 = 1;
          if ((uVar17 & 1) != 0) {
            iVar11 = _fprintf(param_1,&DAT_1005b2b8);
          }
          if (iVar11 == 0) {
LAB_10035808:
            if (iVar11 == 0) {
              return 0;
            }
            if ((uVar17 & 0x10) != 0) {
              iVar11 = _fprintf(param_1,s_Trilinear_1005b294);
            }
          }
          else {
            if ((uVar17 & 2) != 0) {
              iVar11 = _fprintf(param_1,s_Foreshorten_1005b2a8);
            }
            if (iVar11 != 0) {
              if ((uVar17 & 4) != 0) {
                iVar11 = _fprintf(param_1,s_Filter_1005b2a0);
              }
              goto LAB_10035808;
            }
          }
          if (iVar11 == 0) {
            return 0;
          }
          iVar11 = _fprintf(param_1,&DAT_1005b120);
          if (iVar11 == -1) {
            FUN_1000cba0(6);
            return 0;
          }
        }
        iVar11 = RwSetMaterialTextureModes((int)param_4,uVar15);
        if (iVar11 == 0) {
          return 0;
        }
      }
      if (local_100 != uVar9) {
        uVar15 = local_100 & (local_100 ^ uVar9);
        iVar11 = param_2;
        if (uVar15 != 0) {
          for (; iVar11 != 0; iVar11 = iVar11 + -1) {
            iVar12 = _fputc(0x20,param_1);
            if (iVar12 == -1) {
              FUN_1000cba0(6);
              return 0;
            }
          }
          iVar11 = _fprintf(param_1,s_RemoveMaterialMode_1005b150);
          if (iVar11 == -1) {
            FUN_1000cba0(6);
            return 0;
          }
          iVar11 = 1;
          if ((uVar15 & 0x80) != 0) {
            iVar11 = _fprintf(param_1,s_Double_1005b28c);
          }
          if (iVar11 == 0) {
            return 0;
          }
          if ((uVar15 & 0x40) != 0) {
            iVar11 = _fprintf(param_1,s_Decal_1005b284);
          }
          if (iVar11 == 0) {
            return 0;
          }
          iVar11 = _fprintf(param_1,&DAT_1005b120);
          if (iVar11 == -1) {
            FUN_1000cba0(6);
            return 0;
          }
        }
        uVar15 = uVar9 & (local_100 ^ uVar9);
        iVar11 = param_2;
        if (uVar15 != 0) {
          for (; iVar11 != 0; iVar11 = iVar11 + -1) {
            iVar12 = _fputc(0x20,param_1);
            if (iVar12 == -1) {
              FUN_1000cba0(6);
              return 0;
            }
          }
          iVar11 = _fprintf(param_1,s_AddMaterialMode_1005b140);
          if (iVar11 == -1) {
            FUN_1000cba0(6);
            return 0;
          }
          iVar11 = 1;
          if ((uVar15 & 0x80) != 0) {
            iVar11 = _fprintf(param_1,s_Double_1005b28c);
          }
          if (iVar11 == 0) {
            return 0;
          }
          if ((uVar15 & 0x40) != 0) {
            iVar11 = _fprintf(param_1,s_Decal_1005b284);
          }
          if (iVar11 == 0) {
            return 0;
          }
          iVar11 = _fprintf(param_1,&DAT_1005b120);
          if (iVar11 == -1) {
            FUN_1000cba0(6);
            return 0;
          }
        }
        iVar11 = RwSetMaterialModes((int)param_4,uVar9);
        if (iVar11 == 0) {
          return 0;
        }
      }
      goto LAB_10035a2b;
    }
  }
  for (; iVar10 != 0; iVar10 = iVar10 + -1) {
    iVar11 = _fputc(0x20,param_1);
    if (iVar11 == -1) {
      FUN_1000cba0(6);
      return 0;
    }
  }
  if (uVar15 == 0) {
    iVar11 = _fprintf(param_1,s_TextureModes_NULL_1005b1bc);
    if (iVar11 == -1) {
      FUN_1000cba0(6);
      return 0;
    }
  }
  else {
    iVar11 = _fprintf(param_1,s_TextureModes_1005b1ac);
    if (iVar11 == -1) {
      FUN_1000cba0(6);
      return 0;
    }
    iVar11 = 1;
    if ((bVar3 & 1) != 0) {
      iVar11 = _fprintf(param_1,&DAT_1005b2b8);
    }
    if (iVar11 == 0) {
LAB_10035502:
      if (iVar11 == 0) {
        return 0;
      }
      if ((bVar3 & 0x10) != 0) {
        iVar11 = _fprintf(param_1,s_Trilinear_1005b294);
      }
    }
    else {
      if ((bVar3 & 2) != 0) {
        iVar11 = _fprintf(param_1,s_Foreshorten_1005b2a8);
      }
      if (iVar11 != 0) {
        if ((bVar3 & 4) != 0) {
          iVar11 = _fprintf(param_1,s_Filter_1005b2a0);
        }
        goto LAB_10035502;
      }
    }
    if (iVar11 == 0) {
      return 0;
    }
  }
  iVar12 = _fprintf(param_1,&DAT_1005b120);
  iVar11 = param_2;
  if (iVar12 == -1) {
    FUN_1000cba0(6);
    return 0;
  }
  for (; iVar11 != 0; iVar11 = iVar11 + -1) {
    iVar12 = _fputc(0x20,param_1);
    if (iVar12 == -1) {
      FUN_1000cba0(6);
      return 0;
    }
  }
  if (uVar9 == 0) {
    iVar11 = _fprintf(param_1,s_MaterialModes_NULL_1005b198);
    if (iVar11 == -1) {
      FUN_1000cba0(6);
      return 0;
    }
  }
  else {
    iVar11 = _fprintf(param_1,s_MaterialModes_1005b188);
    if (iVar11 == -1) {
      FUN_1000cba0(6);
      return 0;
    }
    iVar11 = 1;
    if ((bVar4 & 0x80) != 0) {
      iVar11 = _fprintf(param_1,s_Double_1005b28c);
    }
    if (iVar11 == 0) {
      return 0;
    }
    if ((bVar4 & 0x40) != 0) {
      iVar11 = _fprintf(param_1,s_Decal_1005b284);
    }
    if (iVar11 == 0) {
      return 0;
    }
  }
  iVar11 = _fprintf(param_1,&DAT_1005b120);
  if (iVar11 == -1) {
    FUN_1000cba0(6);
    return 0;
  }
LAB_10035a2b:
  if ((param_4 == (uint *)0x0) || (local_d8 != piVar8)) {
    for (; param_2 != 0; param_2 = param_2 + -1) {
      iVar11 = _fputc(0x20,param_1);
      if (iVar11 == -1) {
        FUN_1000cba0(6);
        return 0;
      }
    }
    if (piVar8 == (int *)0x0) {
      iVar11 = _fprintf(param_1,s_Texture_NULL_1005b124);
      if (iVar11 == -1) {
        FUN_1000cba0(6);
        return 0;
      }
    }
    else {
      pcVar16 = RwGetTextureName(piVar8,local_80,0x80);
      if ((pcVar16 != (char *)0x0) &&
         (iVar11 = _fprintf(param_1,s_Texture__s_1005b134), iVar11 == -1)) {
        FUN_1000cba0(6);
        return 0;
      }
    }
    if ((param_4 != (uint *)0x0) &&
       (puVar14 = RwSetMaterialTexture(param_4,(uint)piVar8), puVar14 == (uint *)0x0)) {
      return 0;
    }
  }
  return 1;
}


