// 10021da0 FUN_10021da0 [Global]
// program: RWL21.DLL

uint FUN_10021da0(FILE *param_1,undefined4 *param_2,uint param_3)

{
  undefined1 *puVar1;
  uint uVar2;
  undefined1 uVar3;
  size_t sVar4;
  undefined1 *puVar5;
  int iVar6;
  byte *_DstBuf;
  int iVar7;
  uint uVar8;
  uint uVar9;
  undefined1 *puVar10;
  byte bStack_12e;
  byte bStack_12d;
  uint uStack_12c;
  int iStack_128;
  uint local_120;
  uint local_11c;
  int local_118;
  int local_114;
  undefined4 uStack_110;
  int local_10c;
  size_t local_108;
  uint local_104;
  undefined1 local_100 [256];
  
  sVar4 = FUN_10020610(param_1,&local_120,0x1c,4);
  if (sVar4 == 0) {
    return 0;
  }
  if (local_114 == 0) {
    local_114 = local_120 * local_11c;
  }
  puVar10 = (undefined1 *)param_2[0xd];
  if (local_10c == 1) {
    if (((int)local_108 / 3) * 3 != local_108) {
      FUN_1000cba0(0x46);
      return 0;
    }
    sVar4 = _fread(local_100,(int)local_108 / 3,1,param_1);
    if (sVar4 == 0) {
      FUN_1000cba0(10);
      return 0;
    }
    iVar6 = 0;
    puVar5 = puVar10;
    if (0 < (int)local_108 / 3) {
      do {
        puVar1 = local_100 + iVar6;
        iVar6 = iVar6 + 1;
        *puVar5 = *puVar1;
        puVar5 = puVar5 + 3;
      } while (iVar6 < (int)local_108 / 3);
    }
    sVar4 = _fread(local_100,(int)local_108 / 3,1,param_1);
    if (sVar4 == 0) {
      FUN_1000cba0(10);
      return 0;
    }
    iVar6 = 0;
    if (0 < (int)local_108 / 3) {
      puVar5 = puVar10 + 1;
      do {
        puVar1 = local_100 + iVar6;
        iVar6 = iVar6 + 1;
        *puVar5 = *puVar1;
        puVar5 = puVar5 + 3;
      } while (iVar6 < (int)local_108 / 3);
    }
    sVar4 = _fread(local_100,(int)local_108 / 3,1,param_1);
    if (sVar4 == 0) {
      FUN_1000cba0(10);
      return 0;
    }
    iVar6 = 0;
    if (0 < (int)local_108 / 3) {
      puVar5 = puVar10 + 2;
      do {
        puVar1 = local_100 + iVar6;
        iVar6 = iVar6 + 1;
        *puVar5 = *puVar1;
        puVar5 = puVar5 + 3;
      } while (iVar6 < (int)local_108 / 3);
    }
  }
  else if (local_10c == 2) {
    sVar4 = _fread(local_100,local_108,1,param_1);
    if (sVar4 == 0) {
      FUN_1000cba0(10);
      return 0;
    }
    iVar6 = 0;
    puVar5 = puVar10;
    if (0 < (int)local_108) {
      do {
        iVar7 = iVar6 + 1;
        *puVar5 = local_100[iVar6];
        puVar5[1] = local_100[iVar6];
        puVar5[2] = local_100[iVar6];
        puVar5 = puVar5 + 3;
        iVar6 = iVar7;
      } while (iVar7 < (int)local_108);
    }
  }
  if (local_108 == 0) {
    if (local_118 == 1) {
      *puVar10 = 0;
      puVar10[1] = 0;
      puVar10[2] = 0;
      puVar10[3] = 0xff;
      puVar10[4] = 0xff;
      puVar10[5] = 0xff;
      local_108 = 2;
    }
    else if (local_118 == 8) {
      iVar6 = 0;
      do {
        uVar3 = (undefined1)iVar6;
        *puVar10 = uVar3;
        puVar10[1] = uVar3;
        puVar10[2] = uVar3;
        puVar10 = puVar10 + 3;
        iVar6 = iVar6 + 1;
      } while (iVar6 < 0x100);
      local_108 = 0x100;
    }
  }
  iVar6 = local_120 * local_118 + 7;
  local_104 = ((int)(iVar6 + (iVar6 >> 0x1f & 7U)) >> 3) + 1U & 0xfffffffe;
  _DstBuf = (byte *)(**(code **)(PTR_DAT_1005b69c + 0x34c))((local_120 + 7 & 0xfffffff8) << 2);
  if (_DstBuf == (byte *)0x0) {
    FUN_1000cba0(3);
    local_11c = 0;
  }
  else {
    if ((local_118 == 8) &&
       (((*(uint *)(PTR_DAT_1005b69c + 0x20) == local_120 &&
         (((int)local_11c / *(int *)(PTR_DAT_1005b69c + 0x24)) * *(int *)(PTR_DAT_1005b69c + 0x24) -
          local_11c == 0)) ||
        ((*(uint *)(PTR_DAT_1005b69c + 700) != 0 &&
         ((local_120 == *(uint *)(PTR_DAT_1005b69c + 700) &&
          (((int)local_11c / *(int *)(PTR_DAT_1005b69c + 0x2c0)) *
           *(int *)(PTR_DAT_1005b69c + 0x2c0) - local_11c == 0)))))))) {
      param_3 = param_3 & 0xfffffffe;
    }
    switch(uStack_110) {
    case 2:
      uVar8 = 0;
      iStack_128 = 0;
      if (0 < (int)local_11c) {
        do {
          sVar4 = _fread(&bStack_12d,1,1,param_1);
          if (sVar4 == 0) {
            (**(code **)(PTR_DAT_1005b69c + 0x358))(_DstBuf);
            param_2[9] = 0;
            FUN_1000cba0(10);
            return 0;
          }
          if (bStack_12d == 0x80) {
            sVar4 = _fread(&bStack_12d,1,1,param_1);
            if (sVar4 == 0) {
              (**(code **)(PTR_DAT_1005b69c + 0x358))(_DstBuf);
              param_2[9] = 0;
              FUN_1000cba0(10);
              return 0;
            }
            uStack_12c = (uint)bStack_12d;
            if (uStack_12c == 0) {
              bStack_12e = 0x80;
              uVar2 = uStack_12c;
            }
            else {
              sVar4 = _fread(&bStack_12e,1,1,param_1);
              uVar2 = uStack_12c;
              if (sVar4 == 0) {
                (**(code **)(PTR_DAT_1005b69c + 0x358))(_DstBuf);
                param_2[9] = 0;
                FUN_1000cba0(10);
                return 0;
              }
            }
            while (uStack_12c = uVar2 - 1, -1 < (int)uVar2) {
              uVar9 = uVar8 + 1;
              _DstBuf[uVar8] = bStack_12e;
              uVar8 = uVar9;
              uVar2 = uStack_12c;
              if (local_104 == uVar9) {
                FUN_10042b80(_DstBuf,local_120,local_118,param_2,param_3);
                iVar6 = FUN_10042f30((int)_DstBuf,local_120,local_11c,iStack_128,(int)param_2,
                                     param_3);
                if (iVar6 == 0) {
                  (**(code **)(PTR_DAT_1005b69c + 0x358))(_DstBuf);
                  param_2[9] = 0;
                  return 0;
                }
                uVar8 = 0;
                iStack_128 = iStack_128 + 1;
                uVar2 = uStack_12c;
              }
            }
          }
          else {
            _DstBuf[uVar8] = bStack_12d;
            uVar8 = uVar8 + 1;
            if (local_104 == uVar8) {
              FUN_10042b80(_DstBuf,local_120,local_118,param_2,param_3);
              iVar6 = FUN_10042f30((int)_DstBuf,local_120,local_11c,iStack_128,(int)param_2,param_3)
              ;
              if (iVar6 == 0) {
                (**(code **)(PTR_DAT_1005b69c + 0x358))(_DstBuf);
                param_2[9] = 0;
                return 0;
              }
              uVar8 = 0;
              iStack_128 = iStack_128 + 1;
            }
          }
        } while (iStack_128 < (int)local_11c);
      }
      break;
    case 3:
      param_3 = param_3 & 0xfffffffb;
    case 0:
    case 1:
      iVar6 = 0;
      if (0 < (int)local_11c) {
        do {
          sVar4 = _fread(_DstBuf,local_104,1,param_1);
          if (sVar4 == 0) {
            (**(code **)(PTR_DAT_1005b69c + 0x358))(_DstBuf);
            param_2[9] = 0;
            FUN_1000cba0(10);
            return 0;
          }
          FUN_10042b80(_DstBuf,local_120,local_118,param_2,param_3);
          iVar7 = FUN_10042f30((int)_DstBuf,local_120,local_11c,iVar6,(int)param_2,param_3);
          if (iVar7 == 0) {
            (**(code **)(PTR_DAT_1005b69c + 0x358))(_DstBuf);
            param_2[9] = 0;
            return 0;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < (int)local_11c);
      }
    }
    (**(code **)(PTR_DAT_1005b69c + 0x358))(_DstBuf);
    local_11c = local_120 << 0x10 | local_11c;
  }
  return local_11c;
}


