// 10034130 FUN_10034130 [Global]
// program: RWL21.DLL

undefined4 FUN_10034130(FILE *param_1,int param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  float *pfVar6;
  undefined3 extraout_var_00;
  int iVar7;
  uint *puVar8;
  int local_18;
  int local_14;
  float local_10;
  float local_c;
  int local_8;
  FILE *local_4;
  
  for (iVar7 = param_2; iVar7 != 0; iVar7 = iVar7 + -1) {
    iVar2 = _fputc(0x20,param_1);
    if (iVar2 == -1) {
      FUN_1000cba0(6);
      return 0;
    }
  }
  iVar7 = _fprintf(param_1,s_TransformBegin_1005b0f4);
  if (iVar7 == -1) {
    FUN_1000cba0(6);
    return 0;
  }
  for (iVar7 = DAT_1005af10 + param_2; iVar7 != 0; iVar7 = iVar7 + -1) {
    iVar2 = _fputc(0x20,param_1);
    if (iVar2 == -1) {
      FUN_1000cba0(6);
      return 0;
    }
  }
  if (*(char *)(param_3 + 300) == '\0') {
    iVar7 = _fprintf(param_1,s_Transform__f__f__f__f__f__f__f___1005b0ac,
                     (double)*(float *)(param_3 + 0xec),(double)*(float *)(param_3 + 0xf0),
                     (double)*(float *)(param_3 + 0xf4),(double)*(float *)(param_3 + 0xf8),
                     (double)*(float *)(param_3 + 0xfc),(double)*(float *)(param_3 + 0x100),
                     (double)*(float *)(param_3 + 0x104),(double)*(float *)(param_3 + 0x108),
                     (double)*(float *)(param_3 + 0x10c),(double)*(float *)(param_3 + 0x110),
                     (double)*(float *)(param_3 + 0x114),(double)*(float *)(param_3 + 0x118),
                     (double)*(float *)(param_3 + 0x11c),(double)*(float *)(param_3 + 0x120),
                     (double)*(float *)(param_3 + 0x124),(double)*(float *)(param_3 + 0x128));
    if (iVar7 == -1) {
      FUN_1000cba0(6);
      return 0;
    }
  }
  else {
    iVar7 = _fprintf(param_1,s_Identity_1005b0e8);
    if (iVar7 == -1) {
      FUN_1000cba0(6);
      return 0;
    }
  }
  for (iVar7 = DAT_1005af10 + param_2; iVar7 != 0; iVar7 = iVar7 + -1) {
    iVar2 = _fputc(0x20,param_1);
    if (iVar2 == -1) {
      FUN_1000cba0(6);
      return 0;
    }
  }
  iVar7 = _fprintf(param_1,s_JointTransformBegin_1005b094);
  if (iVar7 == -1) {
    FUN_1000cba0(6);
    return 0;
  }
  for (iVar7 = param_2 + DAT_1005af10 * 2; iVar7 != 0; iVar7 = iVar7 + -1) {
    iVar2 = _fputc(0x20,param_1);
    if (iVar2 == -1) {
      FUN_1000cba0(6);
      return 0;
    }
  }
  if (*(char *)(param_3 + 0x170) == '\0') {
    iVar7 = _fprintf(param_1,s_TransformJoint__f__f__f__f__f__f_1005b040,
                     (double)*(float *)(param_3 + 0x130),(double)*(float *)(param_3 + 0x134),
                     (double)*(float *)(param_3 + 0x138),(double)*(float *)(param_3 + 0x13c),
                     (double)*(float *)(param_3 + 0x140),(double)*(float *)(param_3 + 0x144),
                     (double)*(float *)(param_3 + 0x148),(double)*(float *)(param_3 + 0x14c),
                     (double)*(float *)(param_3 + 0x150),(double)*(float *)(param_3 + 0x154),
                     (double)*(float *)(param_3 + 0x158),(double)*(float *)(param_3 + 0x15c),
                     (double)*(float *)(param_3 + 0x160),(double)*(float *)(param_3 + 0x164),
                     (double)*(float *)(param_3 + 0x168),(double)*(float *)(param_3 + 0x16c));
    if (iVar7 == -1) {
      FUN_1000cba0(6);
      return 0;
    }
  }
  else {
    iVar7 = _fprintf(param_1,s_IdentityJoint_1005b084);
    if (iVar7 == -1) {
      FUN_1000cba0(6);
      return 0;
    }
  }
  for (iVar7 = param_2 + DAT_1005af10 * 2; iVar7 != 0; iVar7 = iVar7 + -1) {
    iVar2 = _fputc(0x20,param_1);
    if (iVar2 == -1) {
      FUN_1000cba0(6);
      return 0;
    }
  }
  iVar7 = _fprintf(param_1,s_ClumpBegin_1005b034);
  if (iVar7 == -1) {
    FUN_1000cba0(6);
    return 0;
  }
  bVar1 = RwMaterialBegin();
  if (CONCAT31(extraout_var,bVar1) == 0) {
    return 0;
  }
  puVar8 = (uint *)0x0;
  puVar3 = (uint *)RwCurrentMaterial();
  iVar7 = FUN_10034e20(param_1,DAT_1005af10 * 3 + param_2,puVar3,puVar8);
  if (iVar7 == 0) {
    return 0;
  }
  iVar7 = _fputc(10,param_1);
  if (iVar7 == -1) {
    FUN_1000cba0(6);
    return 0;
  }
  if (*(int *)(param_3 + 0xe8) != 0) {
    for (iVar7 = DAT_1005af10 * 3 + param_2; iVar7 != 0; iVar7 = iVar7 + -1) {
      iVar2 = _fputc(0x20,param_1);
      if (iVar2 == -1) {
        FUN_1000cba0(6);
        return 0;
      }
    }
    iVar7 = _fprintf(param_1,s_Tag__d_1005b02c);
    if (iVar7 == -1) {
      FUN_1000cba0(6);
      return 0;
    }
  }
  uVar4 = FUN_100026f0();
  uVar4 = uVar4 ^ *(uint *)(param_3 + 0x188);
  if (uVar4 != 0) {
    uVar5 = FUN_100026f0();
    uVar5 = uVar5 & uVar4;
    if (uVar5 != 0) {
      for (iVar7 = DAT_1005af10 * 3 + param_2; iVar7 != 0; iVar7 = iVar7 + -1) {
        iVar2 = _fputc(0x20,param_1);
        if (iVar2 == -1) {
          FUN_1000cba0(6);
          return 0;
        }
      }
      iVar7 = _fprintf(param_1,s_RemoveHint_1005b020);
      if (iVar7 == -1) {
        FUN_1000cba0(6);
        return 0;
      }
      if (((uVar5 & 1) == 0) || (iVar7 = _fprintf(param_1,s_Container_1005b114), iVar7 != -1)) {
        if (((uVar5 & 2) == 0) || (iVar7 = _fprintf(param_1,&DAT_1005b110), iVar7 != -1)) {
          if (((uVar5 & 4) == 0) || (iVar7 = _fprintf(param_1,s_Editable_1005b104), iVar7 != -1)) {
            bVar1 = true;
          }
          else {
            FUN_1000cba0(6);
            bVar1 = false;
          }
        }
        else {
          FUN_1000cba0(6);
          bVar1 = false;
        }
      }
      else {
        FUN_1000cba0(6);
        bVar1 = false;
      }
      if (!bVar1) {
        return 0;
      }
      iVar7 = _fprintf(param_1,&DAT_1005b120);
      if (iVar7 == -1) {
        FUN_1000cba0(6);
        return 0;
      }
    }
    uVar4 = *(uint *)(param_3 + 0x188) & uVar4;
    if (uVar4 != 0) {
      for (iVar7 = DAT_1005af10 * 3 + param_2; iVar7 != 0; iVar7 = iVar7 + -1) {
        iVar2 = _fputc(0x20,param_1);
        if (iVar2 == -1) {
          FUN_1000cba0(6);
          return 0;
        }
      }
      iVar7 = _fprintf(param_1,s_AddHint_1005b018);
      if (iVar7 == -1) {
        FUN_1000cba0(6);
        return 0;
      }
      if (((uVar4 & 1) == 0) || (iVar7 = _fprintf(param_1,s_Container_1005b114), iVar7 != -1)) {
        if (((uVar4 & 2) == 0) || (iVar7 = _fprintf(param_1,&DAT_1005b110), iVar7 != -1)) {
          if (((uVar4 & 4) == 0) || (iVar7 = _fprintf(param_1,s_Editable_1005b104), iVar7 != -1)) {
            bVar1 = true;
          }
          else {
            FUN_1000cba0(6);
            bVar1 = false;
          }
        }
        else {
          FUN_1000cba0(6);
          bVar1 = false;
        }
      }
      else {
        FUN_1000cba0(6);
        bVar1 = false;
      }
      if (!bVar1) {
        return 0;
      }
      iVar7 = _fprintf(param_1,&DAT_1005b120);
      if (iVar7 == -1) {
        FUN_1000cba0(6);
        return 0;
      }
    }
  }
  if ((*(int *)(param_3 + 0x18c) != 0) && (*(int *)(param_3 + 0x18c) != 1)) {
    for (iVar7 = DAT_1005af10 * 3 + param_2; iVar7 != 0; iVar7 = iVar7 + -1) {
      iVar2 = _fputc(0x20,param_1);
      if (iVar2 == -1) {
        FUN_1000cba0(6);
        return 0;
      }
    }
    iVar7 = _fprintf(param_1,s_AxisAlignment_1005b008);
    if (iVar7 == -1) {
      FUN_1000cba0(6);
      return 0;
    }
    iVar7 = *(int *)(param_3 + 0x18c);
    if (iVar7 == 2) {
      iVar7 = _fprintf(param_1,s_ZOrientX_1005affc);
      if (iVar7 == -1) {
        FUN_1000cba0(6);
        return 0;
      }
    }
    else if (iVar7 == 3) {
      iVar7 = _fprintf(param_1,s_ZOrientY_1005aff0);
      if (iVar7 == -1) {
        FUN_1000cba0(6);
        return 0;
      }
    }
    else if ((iVar7 == 4) && (iVar7 = _fprintf(param_1,s_XYZ_1005afe8), iVar7 == -1)) {
      FUN_1000cba0(6);
      return 0;
    }
  }
  iVar7 = _fputc(10,param_1);
  if (iVar7 == -1) {
    FUN_1000cba0(6);
    return 0;
  }
  local_14 = 8;
  if (8 < *(int *)(*(int *)(param_3 + 0x88) + 8)) {
    local_18 = 0x3a0;
    do {
      for (iVar7 = DAT_1005af10 * 3 + param_2; iVar7 != 0; iVar7 = iVar7 + -1) {
        iVar2 = _fputc(0x20,param_1);
        if (iVar2 == -1) {
          FUN_1000cba0(6);
          return 0;
        }
      }
      iVar7 = local_18 + *(int *)(param_3 + 0x88);
      if ((*(byte *)(iVar7 + 0x54) & 0x80) == 0) {
        if ((*(byte *)(iVar7 + 0x54) & 0x40) == 0) {
          iVar7 = _fprintf(param_1,s_Vertex___f___f___f_1005af5c,(double)*(float *)(iVar7 + 0xc),
                           (double)*(float *)(iVar7 + 0x10),(double)*(float *)(iVar7 + 0x14));
          if (iVar7 == -1) {
            FUN_1000cba0(6);
            return 0;
          }
        }
        else {
          iVar7 = _fprintf(param_1,s_VertexExt___f___f___f_Normal__f___1005af70,
                           (double)*(float *)(iVar7 + 0xc),(double)*(float *)(iVar7 + 0x10),
                           (double)*(float *)(iVar7 + 0x14),(double)*(float *)(iVar7 + 0x58),
                           (double)*(float *)(iVar7 + 0x5c),(double)*(float *)(iVar7 + 0x60));
          if (iVar7 == -1) {
            FUN_1000cba0(6);
            return 0;
          }
        }
      }
      else {
        pfVar6 = RwGetClumpVertexUV(param_3,local_14 + -7,&local_10);
        if (pfVar6 == (float *)0x0) {
          return 0;
        }
        iVar7 = *(int *)(param_3 + 0x88) + local_18;
        if ((*(byte *)(iVar7 + 0x54) & 0x40) == 0) {
          iVar7 = _fprintf(param_1,s_VertexExt___f___f___f_UV__f__f_1005af98,
                           (double)*(float *)(iVar7 + 0xc),(double)*(float *)(iVar7 + 0x10),
                           (double)*(float *)(iVar7 + 0x14),(double)local_10,(double)local_c);
          if (iVar7 == -1) {
            FUN_1000cba0(6);
            return 0;
          }
        }
        else {
          iVar7 = _fprintf(param_1,s_VertexExt___f___f___f_Normal__f___1005afb8,
                           (double)*(float *)(iVar7 + 0xc),(double)*(float *)(iVar7 + 0x10),
                           (double)*(float *)(iVar7 + 0x14),(double)*(float *)(iVar7 + 0x58),
                           (double)*(float *)(iVar7 + 0x5c),(double)*(float *)(iVar7 + 0x60),
                           (double)local_10,(double)local_c);
          if (iVar7 == -1) {
            FUN_1000cba0(6);
            return 0;
          }
        }
      }
      local_18 = local_18 + 0x74;
      local_14 = local_14 + 1;
    } while (local_14 < *(int *)(*(int *)(param_3 + 0x88) + 8));
  }
  iVar7 = _fputc(10,param_1);
  if (iVar7 == -1) {
    FUN_1000cba0(6);
    return 0;
  }
  local_4 = param_1;
  local_8 = DAT_1005af10 * 3 + param_2;
  iVar7 = RwForAllPolygonsInClumpPointer(param_3,FUN_10035b10,&local_8);
  if (iVar7 == 0) {
    return 0;
  }
  bVar1 = RwMaterialEnd();
  if (CONCAT31(extraout_var_00,bVar1) == 0) {
    return 0;
  }
  for (iVar7 = *(int *)(param_3 + 0x178); iVar7 != 0; iVar7 = *(int *)(iVar7 + 0x184)) {
    iVar2 = FUN_10034130(param_1,DAT_1005af10 * 3 + param_2,iVar7);
    if (iVar2 == 0) {
      return 0;
    }
  }
  for (iVar7 = param_2 + DAT_1005af10 * 2; iVar7 != 0; iVar7 = iVar7 + -1) {
    iVar2 = _fputc(0x20,param_1);
    if (iVar2 == -1) {
      FUN_1000cba0(6);
      return 0;
    }
  }
  iVar7 = _fprintf(param_1,s_ClumpEnd_1005af50);
  if (iVar7 == -1) {
    FUN_1000cba0(6);
    return 0;
  }
  for (iVar7 = param_2 + DAT_1005af10 * 2; iVar7 != 0; iVar7 = iVar7 + -1) {
    iVar2 = _fputc(0x20,param_1);
    if (iVar2 == -1) {
      FUN_1000cba0(6);
      return 0;
    }
  }
  iVar7 = _fprintf(param_1,s_JointTransformEnd_1005af3c);
  if (iVar7 == -1) {
    FUN_1000cba0(6);
    return 0;
  }
  for (; param_2 != 0; param_2 = param_2 + -1) {
    iVar7 = _fputc(0x20,param_1);
    if (iVar7 == -1) {
      FUN_1000cba0(6);
      return 0;
    }
  }
  iVar7 = _fprintf(param_1,s_TransformEnd_1005af2c);
  if (iVar7 != -1) {
    return 1;
  }
  FUN_1000cba0(6);
  return 0;
}


