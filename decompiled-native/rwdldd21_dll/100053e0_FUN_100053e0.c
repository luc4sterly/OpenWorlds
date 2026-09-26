// 100053e0 FUN_100053e0 [Global]
// programa: RWDLDD21.DLL

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_100053e0(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  int *piVar6;
  uint *puVar7;
  undefined4 *puVar8;
  int unaff_retaddr;
  int *piStack_2b8;
  int *piStack_2b4;
  int *piStack_2b0;
  int aiStack_29c [6];
  undefined4 uStack_284;
  undefined4 uStack_250;
  uint auStack_244 [23];
  undefined4 auStack_1e8 [6];
  undefined4 uStack_1d0;
  uint uStack_1b8;
  undefined4 auStack_1b0 [24];
  uint uStack_150;
  uint uStack_13c;
  uint uStack_138;
  uint uStack_134;
  int iStack_118;
  undefined4 auStack_e4 [47];
  undefined4 uStack_28;
  int iStack_8;
  
  *(undefined4 *)(param_2 + 0xa8) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(param_2 + 0x58) = *(undefined4 *)(param_1 + 0x14);
  uVar4 = (-(uint)(*(int *)(param_1 + 0x10) == 1) & 0x3800) + 0x800;
  if (DAT_10036048 == 0) {
    piVar6 = aiStack_29c;
    for (iVar3 = 0x1b; piVar6 = piVar6 + 1, iVar3 != 0; iVar3 = iVar3 + -1) {
      *piVar6 = 0;
    }
    auStack_244[5] = uVar4 | 0x2040;
    aiStack_29c[4] = param_4;
    piStack_2b4 = (int *)(param_2 + 0xc);
    piStack_2b0 = (int *)0x0;
    aiStack_29c[3] = param_5;
    aiStack_29c[1] = 0x6c;
    aiStack_29c[2] = 7;
    piStack_2b8 = aiStack_29c + 1;
    iVar3 = (**(code **)(*DAT_10036030 + 0x18))(DAT_10036030);
    if (iVar3 != 0) {
      return 0;
    }
    *(uint *)(param_2 + 0x228) = *(uint *)(param_2 + 0x228) & 0xfffffffe;
    if (DAT_10036058 == 0) {
      *(undefined4 *)(param_2 + 0x10) = 0;
    }
    else {
      piVar6 = aiStack_29c;
      for (iVar3 = 0x1b; iVar3 != 0; iVar3 = iVar3 + -1) {
        *piVar6 = 0;
        piVar6 = piVar6 + 1;
      }
      auStack_244[4] = uVar4 | 0x22000;
      aiStack_29c[3] = param_3;
      aiStack_29c[2] = param_4;
      piStack_2b4 = (int *)0x0;
      aiStack_29c[0] = 0x6c;
      aiStack_29c[1] = 0x47;
      uStack_284 = *(undefined4 *)(unaff_retaddr + 0x14);
      piStack_2b8 = (int *)(param_2 + 0x10);
      iVar3 = (**(code **)(*DAT_10036030 + 0x18))(DAT_10036030,aiStack_29c);
      if (iVar3 != 0) {
        return 0;
      }
      iVar3 = (**(code **)(**(int **)(param_2 + 0xc) + 0xc))
                        (*(int **)(param_2 + 0xc),*(undefined4 *)(param_2 + 0x10));
      if (iVar3 != 0) {
        return 0;
      }
    }
  }
  else {
    *(int **)(param_2 + 0xc) = DAT_1003603c;
    piStack_2b0 = DAT_1003603c;
    piStack_2b4 = (int *)0x10005435;
    (**(code **)(*DAT_1003603c + 4))();
    if ((DAT_10036058 == 0) || (DAT_10036040 == (int *)0x0)) {
      *(undefined4 *)(param_2 + 0x10) = 0;
    }
    else {
      *(int **)(param_2 + 0x10) = DAT_10036040;
      piStack_2b4 = DAT_10036040;
      piStack_2b8 = (int *)0x10005455;
      (**(code **)(*DAT_10036040 + 4))();
    }
    *(uint *)(param_2 + 0x228) = *(uint *)(param_2 + 0x228) | 1;
  }
  piVar6 = aiStack_29c;
  for (iVar3 = 0x1b; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar6 = 0;
    piVar6 = piVar6 + 1;
  }
  piStack_2b4 = aiStack_29c;
  aiStack_29c[0] = 0x6c;
  piStack_2b8 = *(int **)(param_2 + 0xc);
  iVar3 = (**(code **)(*piStack_2b8 + 0x58))();
  if (iVar3 == -0x7789fe3e) {
    puVar7 = auStack_244 + 3;
    for (iVar3 = 0x1b; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar7 = 0;
      puVar7 = puVar7 + 1;
    }
    auStack_244[3] = 0x6c;
    auStack_244[4] = 1;
    uStack_1d0 = 0x4000;
    (**(code **)(*DAT_10036030 + 0x24))(DAT_10036030,0x10,auStack_244 + 3,0,&LAB_10001b40);
    if (DAT_10036038 != (int *)0x0) {
      (**(code **)(*DAT_10036038 + 0x6c))(DAT_10036038);
    }
    if (DAT_1003603c != DAT_10036038) {
      (**(code **)(*DAT_1003603c + 0x6c))(DAT_1003603c);
    }
    iVar3 = (**(code **)(**(int **)(param_2 + 0xc) + 0x58))(*(int **)(param_2 + 0xc),&piStack_2b8);
  }
  if (iVar3 == 0) {
    puVar2 = (undefined4 *)(**(code **)(DAT_100394fc + 0x34c))(0x38);
    if (puVar2 == (undefined4 *)0x0) {
      uVar1 = 0;
    }
    else {
      *(undefined4 **)(*(int *)(param_2 + 0x100) + 0x2c) = puVar2;
      *(undefined4 **)(*(int *)(param_2 + 0x104) + 0x2c) = puVar2;
      *puVar2 = *(undefined4 *)(param_2 + 0xc);
      *(undefined4 *)(*(int *)(param_2 + 0x100) + 4) = DAT_10038b44;
      **(undefined4 **)(param_2 + 0x100) = 2;
      *(undefined4 *)(*(int *)(param_2 + 0x100) + 8) = DAT_10038b48;
      *(undefined4 *)(*(int *)(param_2 + 0x100) + 0xc) = DAT_10038b4c;
      *(undefined4 *)(*(int *)(param_2 + 0x100) + 0x10) = DAT_10038b50;
      *(undefined4 *)(*(int *)(param_2 + 0x100) + 0x14) = DAT_10038b54;
      puVar5 = &DAT_10038b38;
      puVar8 = puVar2;
      for (iVar3 = 8; puVar8 = puVar8 + 1, iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar8 = *puVar5;
        puVar5 = puVar5 + 1;
      }
      puVar2[9] = 0;
      puVar2[0xb] = 0;
      puVar2[0xd] = param_2;
      *(undefined4 *)(param_2 + 0x108) = *(undefined4 *)(param_2 + 0xc);
      *(int *)(*(int *)(param_2 + 0x100) + 0x1c) = aiStack_29c[1];
      *(int *)(*(int *)(param_2 + 0x100) + 0x20) = aiStack_29c[0];
      *(undefined4 *)(*(int *)(param_2 + 0x100) + 0x24) = uStack_250;
      *(int *)(*(int *)(param_2 + 0x100) + 0x28) = aiStack_29c[2];
      puVar7 = (uint *)(*(int *)(param_2 + 0x100) + 0x40);
      *puVar7 = *puVar7 | 2;
      piVar6 = *(int **)(param_2 + 0x10);
      if (piVar6 == (int *)0x0) {
        *(undefined4 *)(*(int *)(param_2 + 0x104) + 0x1c) = 0;
        *(undefined4 *)(*(int *)(param_2 + 0x104) + 0x20) = 0;
        *(undefined4 *)(*(int *)(param_2 + 0x104) + 0x28) = 0;
        *(undefined4 *)(*(int *)(param_2 + 0x104) + 0x24) = 0;
        **(undefined4 **)(param_2 + 0x104) = 3;
        *(undefined4 *)(*(int *)(param_2 + 0x104) + 4) = 0;
        *(undefined4 *)(*(int *)(param_2 + 0x104) + 8) = 0;
        *(undefined4 *)(*(int *)(param_2 + 0x104) + 0xc) = 0;
        *(undefined4 *)(*(int *)(param_2 + 0x104) + 0x10) = 0;
        *(undefined4 *)(*(int *)(param_2 + 0x104) + 0x14) = 0;
        puVar7 = (uint *)(*(int *)(param_2 + 0x104) + 0x40);
        *puVar7 = *puVar7 | 2;
      }
      else {
        puVar2 = (undefined4 *)&stack0xfffffd5c;
        for (iVar3 = 0x1b; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar2 = 0;
          puVar2 = puVar2 + 1;
        }
        iVar3 = (**(code **)(*piVar6 + 0x58))(piVar6,&stack0xfffffd5c);
        if (iVar3 == -0x7789fe3e) {
          puVar7 = auStack_244 + 3;
          for (iVar3 = 0x1b; iVar3 != 0; iVar3 = iVar3 + -1) {
            *puVar7 = 0;
            puVar7 = puVar7 + 1;
          }
          auStack_244[3] = 0x6c;
          auStack_244[4] = 1;
          uStack_1d0 = 0x4000;
          (**(code **)(*DAT_10036030 + 0x24))(DAT_10036030,0x10,auStack_244 + 3,0,&LAB_10001b40);
          if (DAT_10036038 != (int *)0x0) {
            (**(code **)(*DAT_10036038 + 0x6c))(DAT_10036038);
          }
          if (DAT_1003603c != DAT_10036038) {
            (**(code **)(*DAT_1003603c + 0x6c))(DAT_1003603c);
          }
          iVar3 = (**(code **)(**(int **)(param_2 + 0xc) + 0x58))
                            (*(int **)(param_2 + 0xc),&piStack_2b8);
        }
        if (iVar3 != 0) {
          return 0;
        }
        *(int *)(*(int *)(param_2 + 0x104) + 0x1c) = aiStack_29c[1];
        *(int *)(*(int *)(param_2 + 0x104) + 0x20) = aiStack_29c[0];
        *(int *)(*(int *)(param_2 + 0x104) + 0x28) = aiStack_29c[2];
        *(undefined4 *)(*(int *)(param_2 + 0x104) + 0x24) = *(undefined4 *)(iStack_8 + 0x14);
        **(undefined4 **)(param_2 + 0x104) = 3;
        *(undefined4 *)(*(int *)(param_2 + 0x104) + 4) = *(undefined4 *)(iStack_8 + 0x14);
        *(undefined4 *)(*(int *)(param_2 + 0x104) + 8) = 0;
        *(undefined4 *)(*(int *)(param_2 + 0x104) + 0xc) = 0;
        *(undefined4 *)(*(int *)(param_2 + 0x104) + 0x10) = 0;
        *(undefined4 *)(*(int *)(param_2 + 0x104) + 0x14) = 0;
        *(uint *)(*(int *)(param_2 + 0x104) + 0x40) =
             *(uint *)(*(int *)(param_2 + 0x104) + 0x40) | 2;
      }
      iVar3 = (**(code **)**(undefined4 **)(param_2 + 0xc))
                        (*(undefined4 **)(param_2 + 0xc),iStack_8,param_2 + 0x14);
      if (iVar3 == -0x7789fe3e) {
        puVar7 = auStack_244;
        for (iVar3 = 0x1b; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar7 = 0;
          puVar7 = puVar7 + 1;
        }
        auStack_244[0] = 0x6c;
        auStack_244[1] = 1;
        auStack_1e8[3] = 0x4000;
        (**(code **)(*DAT_10036030 + 0x24))(DAT_10036030,0x10,auStack_244,0,&LAB_10001b40);
        if (DAT_10036038 != (int *)0x0) {
          (**(code **)(*DAT_10036038 + 0x6c))(DAT_10036038);
        }
        if (DAT_1003603c != DAT_10036038) {
          (**(code **)(*DAT_1003603c + 0x6c))(DAT_1003603c);
        }
        iVar3 = (**(code **)**(undefined4 **)(param_2 + 0xc))
                          (*(undefined4 **)(param_2 + 0xc),uStack_28,param_2 + 0x14);
      }
      if (iVar3 == 0) {
        piVar6 = *(int **)(param_2 + 0x14);
        if (piVar6 == (int *)0x0) {
          if (piStack_2b4 != (int *)0x0) {
            (**(code **)(DAT_100394fc + 0x358))(piStack_2b4);
            *(undefined4 *)(*(int *)(param_2 + 0x100) + 0x2c) = 0;
            *(undefined4 *)(*(int *)(param_2 + 0x104) + 0x2c) = 0;
          }
          uVar1 = 0;
        }
        else {
          puVar2 = auStack_1b0;
          for (iVar3 = 0x33; iVar3 != 0; iVar3 = iVar3 + -1) {
            *puVar2 = 0;
            puVar2 = puVar2 + 1;
          }
          auStack_1b0[0] = 0xcc;
          puVar2 = auStack_e4;
          for (iVar3 = 0x33; iVar3 != 0; iVar3 = iVar3 + -1) {
            *puVar2 = 0;
            puVar2 = puVar2 + 1;
          }
          puVar2 = auStack_1b0;
          auStack_e4[0] = 0xcc;
          iVar3 = (**(code **)(*piVar6 + 0x10))(piVar6,puVar2,auStack_e4);
          if (iVar3 == 0) {
            if (((uStack_138 & 8) == 0) && ((uStack_138 & 4) != 0)) {
              *(undefined4 *)(param_2 + 0x8c) = 1;
            }
            else {
              *(undefined4 *)(param_2 + 0x8c) = 0;
            }
            *(uint *)(param_2 + 0x84) = uStack_13c & 0xc0000;
            *(uint *)(param_2 + 0x80) = uStack_1b8 & 0x20;
            *(uint *)(param_2 + 0x78) = uStack_150 & 0x200;
            *(uint *)(param_2 + 0x7c) = uStack_13c & 0x3000;
            *(undefined4 *)(param_2 + 0x88) = 0;
            if (((uStack_13c & 0x3000) != 0) && ((~uStack_13c & 0x1000) != 0)) {
              *(undefined4 *)(param_2 + 0x88) = 1;
            }
            *(undefined4 *)(param_2 + 0x74) = 0;
            *(undefined4 *)(param_2 + 0x70) = 1;
            *(undefined4 *)(param_2 + 0x6c) = 1;
            *(undefined4 *)(param_2 + 0x68) = 1;
            *(undefined4 *)(param_2 + 100) = 1;
            *(undefined4 *)(param_2 + 0x5c) = 1;
            if ((uStack_134 & 2) != 0) {
              *(undefined4 *)(param_2 + 0x6c) = 2;
              *(undefined4 *)(param_2 + 100) = 2;
              *(undefined4 *)(param_2 + 0x5c) = 2;
            }
            if ((uStack_134 & 4) != 0) {
              *(undefined4 *)(param_2 + 100) = 3;
              *(undefined4 *)(param_2 + 0x68) = 3;
              *(undefined4 *)(param_2 + 0x5c) = 3;
              *(undefined4 *)(param_2 + 0x60) = 3;
              *(undefined4 *)(param_2 + 0x74) = 1;
            }
            if ((uStack_134 & 8) != 0) {
              *(undefined4 *)(param_2 + 100) = 4;
              *(undefined4 *)(param_2 + 0x5c) = 4;
              *(undefined4 *)(param_2 + 0x74) = 1;
            }
            if ((uStack_134 & 0x10) != 0) {
              *(undefined4 *)(param_2 + 0x5c) = 5;
              *(undefined4 *)(param_2 + 0x60) = 5;
              *(undefined4 *)(param_2 + 0x74) = 1;
            }
            if ((uStack_134 & 0x20) != 0) {
              *(undefined4 *)(param_2 + 0x5c) = 6;
              *(undefined4 *)(param_2 + 0x74) = 1;
            }
            DAT_10038a4c = *(undefined4 *)(param_2 + 0x74);
            _DAT_10038ac4 = DAT_10038a4c;
            if (iStack_118 == 0) {
              *(undefined4 *)(param_2 + 0x44) = 0x10000;
              *(undefined4 *)(param_2 + 0x48) = 0x10000;
              *(undefined4 *)(param_2 + 0x4c) = 0x10000;
              *(undefined4 *)(param_2 + 0x50) = 0x10000;
            }
            else {
              *(int *)(param_2 + 0x44) = iStack_118;
              *(int *)(param_2 + 0x48) = iStack_118;
              *(int *)(param_2 + 0x4c) = iStack_118;
              *(int *)(param_2 + 0x50) = iStack_118;
            }
          }
          else {
            *(undefined4 *)(param_2 + 0x78) = 0;
            *(undefined4 *)(param_2 + 0x8c) = 0;
            *(undefined4 *)(param_2 + 0x74) = 0;
            *(undefined4 *)(param_2 + 0x7c) = 0;
            *(undefined4 *)(param_2 + 0x88) = 0;
            *(undefined4 *)(param_2 + 0x70) = 1;
            *(undefined4 *)(param_2 + 0x6c) = 1;
            *(undefined4 *)(param_2 + 0x68) = 1;
            *(undefined4 *)(param_2 + 100) = 1;
            *(undefined4 *)(param_2 + 0x5c) = 1;
            DAT_10038a4c = 0;
            _DAT_10038ac4 = 0;
            *(undefined4 *)(param_2 + 0x44) = 0x2000;
            *(undefined4 *)(param_2 + 0x48) = 0x2000;
            *(undefined4 *)(param_2 + 0x4c) = 0x2000;
            *(undefined4 *)(param_2 + 0x50) = 0x2000;
          }
          auStack_1e8[1] = 0;
          auStack_1e8[2] = *(undefined4 *)(param_2 + 0x8c);
          iVar3 = (**(code **)(**(int **)(param_2 + 0x14) + 0x38))
                            (*(int **)(param_2 + 0x14),&LAB_10005cc0,auStack_1e8 + 1);
          if (iVar3 == 0) {
            puVar2 = auStack_1e8;
            puVar8 = &DAT_10038b08;
            for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
              *puVar8 = *puVar2;
              puVar2 = puVar2 + 1;
              puVar8 = puVar8 + 1;
            }
            uVar1 = 1;
            *(int *)param_2 = param_2;
          }
          else {
            if (puVar2 != (undefined4 *)0x0) {
              (**(code **)(DAT_100394fc + 0x358))(puVar2);
              *(undefined4 *)(*(int *)(param_2 + 0x100) + 0x2c) = 0;
              *(undefined4 *)(*(int *)(param_2 + 0x104) + 0x2c) = 0;
            }
            uVar1 = 0;
          }
        }
      }
      else {
        if (piStack_2b4 != (int *)0x0) {
          (**(code **)(DAT_100394fc + 0x358))(piStack_2b4);
          *(undefined4 *)(*(int *)(param_2 + 0x100) + 0x2c) = 0;
          *(undefined4 *)(*(int *)(param_2 + 0x104) + 0x2c) = 0;
        }
        uVar1 = 0;
      }
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


