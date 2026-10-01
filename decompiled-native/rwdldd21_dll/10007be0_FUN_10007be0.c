// 10007be0 FUN_10007be0 [Global]
// program: RWDLDD21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_10007be0(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_EBX;
  int iVar4;
  undefined4 *puVar5;
  undefined4 unaff_EBP;
  int iVar6;
  int unaff_ESI;
  int unaff_EDI;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  undefined4 local_6c [12];
  undefined4 uStack_3c;
  undefined4 uStack_24;
  
  iVar4 = DAT_10038b68;
  bVar7 = DAT_10036048 == 0;
  iVar2 = param_1 * 0x28;
  bVar8 = *(int *)(iVar2 + 0x14 + DAT_10036064) != DAT_10038b68;
  if (DAT_10036030 == (int *)0x0) {
    DAT_10036060 = param_1;
    DAT_100360b0 = 1;
    return 1;
  }
  if (*(int *)(DAT_100394fc + 0xc) != 0) {
    return 0;
  }
  puVar5 = local_6c;
  for (iVar3 = 0x1b; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  local_6c[0] = 0x6c;
  bVar1 = false;
  if ((DAT_10036030 != (int *)0x0) &&
     (iVar3 = (**(code **)(*DAT_10036030 + 0x30))(DAT_10036030,local_6c), iVar3 == 0)) {
    bVar1 = true;
  }
  iVar3 = 0;
  FUN_10004130(0x10038a98);
  FUN_10004130(0x10038a20);
  if ((bVar8) && (0 < DAT_10036180)) {
    iVar6 = 0;
    do {
      if (*(int **)(DAT_1003617c + iVar6) != (int *)0x0) {
        FUN_10008370(*(int **)(DAT_1003617c + iVar6));
      }
      iVar6 = iVar6 + 4;
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_10036180);
  }
  if (DAT_10036044 != (int *)0x0) {
    (**(code **)(*DAT_10036044 + 8))(DAT_10036044);
    DAT_10036044 = (int *)0x0;
  }
  if (DAT_10036040 != (int *)0x0) {
    (**(code **)(*DAT_10036040 + 8))(DAT_10036040);
    DAT_10036040 = (int *)0x0;
  }
  if (DAT_10036038 != (int *)0x0) {
    (**(code **)(*DAT_10036038 + 8))(DAT_10036038);
    DAT_10036038 = (int *)0x0;
  }
  if (((DAT_10036030 != (int *)0x0) && (!bVar7)) &&
     ((iVar3 = (**(code **)(*DAT_10036030 + 0x4c))(DAT_10036030), iVar3 != 0 ||
      (iVar3 = (**(code **)(*DAT_10036030 + 0x50))(DAT_10036030,0,8), iVar3 != 0)))) {
    iVar2 = DAT_10036054;
    if (DAT_10036054 == 0) {
      iVar2 = DAT_10036050;
    }
    iVar2 = (**(code **)(*DAT_10036030 + 0x50))(DAT_10036030,iVar2,0x11);
    bVar7 = iVar2 != 0;
    if (unaff_ESI != 0) {
      if (bVar7) goto LAB_10007dd0;
      iVar2 = (**(code **)(*DAT_10036030 + 0x54))(DAT_10036030,local_6c[0],iVar4,uStack_24);
      if (iVar2 != 0) {
        bVar7 = true;
      }
    }
    if ((!bVar7) && (iVar2 = FUN_10008930(0x11), iVar2 == 0)) {
      bVar7 = true;
    }
LAB_10007dd0:
    iVar2 = 0;
    if ((unaff_EDI != 0) && (0 < DAT_10036180)) {
      iVar4 = 0;
      do {
        if (*(undefined4 **)(DAT_1003617c + iVar4) != (undefined4 *)0x0) {
          FUN_10008770(*(undefined4 **)(DAT_1003617c + iVar4));
        }
        iVar4 = iVar4 + 4;
        iVar2 = iVar2 + 1;
      } while (iVar2 < DAT_10036180);
    }
    iVar2 = 0;
    if (!bVar7) {
      iVar4 = 0x80;
      _DAT_10038a28 = 0;
      DAT_10038a24 = 0;
      _DAT_10038a20 = 0x80;
      DAT_10038a2c = 0;
      DAT_10038a30 = 0;
      DAT_10038a3c = 0;
      DAT_10038a40 = 0;
      DAT_10038a34 = 200;
      DAT_10038a38 = 10;
      DAT_10038a44 = 0x14;
      DAT_10038a50 = 0;
      do {
        iVar2 = iVar2 + 1;
        iVar4 = iVar4 / 2;
      } while (0 < iVar4);
      DAT_10038a48 = iVar2;
      FUN_10003d50((int *)&DAT_10038a98,0x10);
    }
    return 0;
  }
  if (bVar8) {
    if (DAT_10036034 != (int *)0x0) {
      (**(code **)(*DAT_10036034 + 8))(DAT_10036034);
      DAT_10036034 = (int *)0x0;
    }
    if (DAT_10036030 != (int *)0x0) {
      (**(code **)(*DAT_10036030 + 8))(DAT_10036030);
      DAT_10036030 = (int *)0x0;
    }
    iVar3 = *(int *)(iVar2 + 0x14 + DAT_10036064);
    iVar6 = DirectDrawCreate(iVar3,&DAT_10036030,0);
    if (iVar6 == 0) {
      DAT_10038b68 = iVar3;
      iVar3 = (**(code **)*DAT_10036030)(DAT_10036030,&DAT_10034110,&DAT_10036034);
      bVar9 = false;
      if (iVar3 != 0) {
        if (DAT_10036030 != (int *)0x0) {
          (**(code **)(*DAT_10036030 + 8))(DAT_10036030);
          DAT_10036030 = (int *)0x0;
        }
        bVar9 = true;
      }
      if (!bVar9) goto LAB_100080ab;
    }
    iVar3 = 0;
    iVar2 = DirectDrawCreate(iVar4,&DAT_10036030);
    if (iVar2 != 0) {
      return 0;
    }
    DAT_10038b68 = unaff_EBX;
    iVar2 = (**(code **)*DAT_10036030)(DAT_10036030,&DAT_10034110,&DAT_10036034);
    if (iVar2 != 0) {
      return 0;
    }
    if ((bVar7) || (iVar3 == 0)) {
      iVar2 = (**(code **)(*DAT_10036030 + 0x50))(DAT_10036030,0,8);
      bVar7 = false;
    }
    else {
      iVar2 = DAT_10036054;
      if (DAT_10036054 == 0) {
        iVar2 = DAT_10036050;
      }
      iVar2 = (**(code **)(*DAT_10036030 + 0x50))(DAT_10036030,iVar2,0x11);
      bVar7 = iVar2 != 0;
      if (bVar7) goto LAB_10008000;
      iVar2 = (**(code **)(*DAT_10036030 + 0x54))(DAT_10036030,unaff_EDI,unaff_EBP,uStack_3c);
    }
    if (iVar2 != 0) {
      bVar7 = true;
    }
    if ((!bVar7) && (iVar2 = FUN_10008930(0x11), iVar2 == 0)) {
      bVar7 = true;
    }
LAB_10008000:
    iVar2 = 0;
    if (0 < DAT_10036180) {
      iVar4 = 0;
      do {
        if (*(undefined4 **)(DAT_1003617c + iVar4) != (undefined4 *)0x0) {
          FUN_10008770(*(undefined4 **)(DAT_1003617c + iVar4));
        }
        iVar4 = iVar4 + 4;
        iVar2 = iVar2 + 1;
      } while (iVar2 < DAT_10036180);
    }
    iVar2 = 0;
    if (!bVar7) {
      iVar4 = 0x80;
      _DAT_10038a28 = 0;
      DAT_10038a24 = 0;
      _DAT_10038a20 = 0x80;
      DAT_10038a2c = 0;
      DAT_10038a30 = 0;
      DAT_10038a3c = 0;
      DAT_10038a40 = 0;
      DAT_10038a34 = 200;
      DAT_10038a38 = 10;
      DAT_10038a44 = 0x14;
      DAT_10038a50 = 0;
      do {
        iVar2 = iVar2 + 1;
        iVar4 = iVar4 / 2;
      } while (0 < iVar4);
      DAT_10038a48 = iVar2;
      FUN_10003d50((int *)&DAT_10038a98,0x10);
    }
    return 0;
  }
LAB_100080ab:
  if ((*(uint *)(iVar2 + 0x10 + DAT_10036064) & 2) == 0) {
    iVar3 = DAT_10036054;
    if (DAT_10036054 == 0) {
      iVar3 = DAT_10036050;
    }
    iVar3 = (**(code **)(*DAT_10036030 + 0x50))(DAT_10036030,iVar3,0x11);
    if (iVar3 != 0) {
      bVar9 = true;
      goto LAB_10008155;
    }
    puVar5 = (undefined4 *)(iVar2 + DAT_10036064);
    iVar2 = (**(code **)(*DAT_10036030 + 0x54))(DAT_10036030,*puVar5,puVar5[1],puVar5[2]);
    if (iVar2 == 0) {
      iVar2 = FUN_10008930(0x11);
      bVar9 = false;
      goto joined_r0x1000814e;
    }
  }
  else {
    iVar2 = (**(code **)(*DAT_10036030 + 0x50))(DAT_10036030,0,8);
    bVar9 = iVar2 != 0;
    (**(code **)(*DAT_10036030 + 0x50))(DAT_10036030,0,8);
    if (!bVar9) {
      iVar2 = FUN_10008930(8);
joined_r0x1000814e:
      if (iVar2 == 0) {
        bVar9 = true;
      }
LAB_10008155:
      if (!bVar9) {
        iVar2 = 0;
        if ((bVar8) && (iVar4 = 0, 0 < DAT_10036180)) {
          do {
            if (*(undefined4 **)(DAT_1003617c + iVar2) != (undefined4 *)0x0) {
              FUN_10008770(*(undefined4 **)(DAT_1003617c + iVar2));
            }
            iVar2 = iVar2 + 4;
            iVar4 = iVar4 + 1;
          } while (iVar4 < DAT_10036180);
        }
        DAT_10038a48 = 0;
        iVar2 = 0x80;
        _DAT_10038a28 = 0;
        DAT_10038a24 = 0;
        _DAT_10038a20 = 0x80;
        DAT_10038a2c = 0;
        DAT_10038a30 = 0;
        DAT_10038a3c = 0;
        DAT_10038a40 = 0;
        DAT_10038a50 = 0;
        DAT_10038a34 = 200;
        DAT_10038a38 = 10;
        DAT_10038a44 = 0x14;
        do {
          DAT_10038a48 = DAT_10038a48 + 1;
          iVar2 = iVar2 / 2;
        } while (0 < iVar2);
        FUN_10003d50((int *)&DAT_10038a98,0x10);
        DAT_100360b0 = 1;
        DAT_10036060 = param_1;
        return 1;
      }
    }
  }
  if ((!bVar1) || (bVar7)) {
    iVar2 = (**(code **)(*DAT_10036030 + 0x50))(DAT_10036030,0,8);
    bVar7 = iVar2 != 0;
    if (bVar7) goto LAB_100081f4;
    iVar2 = FUN_10008930(8);
  }
  else {
    iVar2 = DAT_10036054;
    if (DAT_10036054 == 0) {
      iVar2 = DAT_10036050;
    }
    iVar2 = (**(code **)(*DAT_10036030 + 0x50))(DAT_10036030,iVar2,0x11);
    if (iVar2 != 0) {
      bVar7 = true;
      goto LAB_100081f4;
    }
    iVar2 = (**(code **)(*DAT_10036030 + 0x54))(DAT_10036030,local_6c[0],iVar4,uStack_24);
    bVar7 = iVar2 != 0;
    if (bVar7) goto LAB_100081f4;
    iVar2 = FUN_10008930(0x11);
  }
  if (iVar2 == 0) {
    bVar7 = true;
  }
LAB_100081f4:
  iVar2 = 0;
  if ((unaff_EDI != 0) && (iVar4 = 0, 0 < DAT_10036180)) {
    do {
      if (*(undefined4 **)(DAT_1003617c + iVar2) != (undefined4 *)0x0) {
        FUN_10008770(*(undefined4 **)(DAT_1003617c + iVar2));
      }
      iVar2 = iVar2 + 4;
      iVar4 = iVar4 + 1;
    } while (iVar4 < DAT_10036180);
  }
  iVar2 = 0;
  if (!bVar7) {
    iVar4 = 0x80;
    _DAT_10038a28 = 0;
    DAT_10038a24 = 0;
    _DAT_10038a20 = 0x80;
    DAT_10038a2c = 0;
    DAT_10038a30 = 0;
    DAT_10038a3c = 0;
    DAT_10038a40 = 0;
    DAT_10038a34 = 200;
    DAT_10038a38 = 10;
    DAT_10038a44 = 0x14;
    DAT_10038a50 = 0;
    do {
      iVar2 = iVar2 + 1;
      iVar4 = iVar4 / 2;
    } while (0 < iVar4);
    DAT_10038a48 = iVar2;
    FUN_10003d50((int *)&DAT_10038a98,0x10);
  }
  return 0;
}


