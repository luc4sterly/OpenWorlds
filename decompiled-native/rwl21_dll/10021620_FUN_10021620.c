// 10021620 FUN_10021620 [Global]
// program: RWL21.DLL

uint FUN_10021620(FILE *param_1,undefined4 *param_2,uint param_3)

{
  bool bVar1;
  size_t sVar2;
  int iVar3;
  byte *_DstBuf;
  undefined1 *puVar4;
  uint uVar5;
  undefined1 *puVar6;
  int iVar7;
  char cStack_446;
  byte bStack_445;
  int iStack_444;
  int local_440;
  uint local_430;
  uint local_42c;
  uint local_428;
  uint local_424;
  short local_41e;
  uint local_41c;
  uint local_404;
  undefined1 local_400 [10];
  byte local_3f6;
  byte local_3f5;
  byte local_3f4;
  byte local_3f3;
  byte local_3f2;
  byte local_3f1;
  byte local_3f0;
  byte local_3ef;
  undefined2 local_3ee;
  byte local_3ec;
  byte local_3eb;
  byte local_3ea;
  byte local_3e9;
  byte local_3e8;
  byte local_3e7;
  undefined1 local_3e4;
  undefined1 local_3e3;
  byte local_3e2;
  byte local_3e1;
  byte local_3e0;
  byte local_3df;
  byte local_3d2;
  byte local_3d1;
  byte local_3d0;
  byte local_3cf;
  
  puVar6 = (undefined1 *)param_2[0xd];
  sVar2 = _fread(local_400 + 2,0x10,1,param_1);
  if (sVar2 == 0) {
    FUN_1000cba0(10);
    local_424 = 0;
  }
  else {
    local_430 = ((uint)local_3f3 << 0x10 | (uint)local_3f5) << 8 | (uint)local_3f4 << 0x10 |
                (uint)local_3f6;
    local_42c = ((uint)local_3ef << 0x10 | (uint)local_3f1) << 8 | (uint)local_3f0 << 0x10 |
                (uint)local_3f2;
    sVar2 = _fread(&local_3ee,local_42c - 4,1,param_1);
    if (sVar2 == 0) {
      FUN_1000cba0(10);
      local_424 = 0;
    }
    else {
      if (local_42c == 0xc) {
        local_428 = (uint)local_3ee;
        local_424 = (uint)CONCAT11(local_3eb,local_3ec);
        uVar5 = 0;
        local_41e = CONCAT11(local_3e7,local_3e8);
        local_41c = 0;
      }
      else {
        local_428 = ((uint)local_3eb << 0x10 | (uint)local_3ee._1_1_) << 8 | (uint)local_3ec << 0x10
                    | (uint)(byte)local_3ee;
        local_424 = ((uint)local_3e7 << 0x10 | (uint)local_3e9) << 8 | (uint)local_3e8 << 0x10 |
                    (uint)local_3ea;
        local_41e = CONCAT11(local_3e3,local_3e4);
        local_41c = ((uint)local_3df << 0x10 | (uint)local_3e1) << 8 | (uint)local_3e0 << 0x10 |
                    (uint)local_3e2;
        uVar5 = ((uint)local_3cf << 0x10 | (uint)local_3d1) << 8 | (uint)local_3d0 << 0x10 |
                (uint)local_3d2;
        if (local_41c == 2) {
          FUN_1000cba0(10);
          return 0;
        }
      }
      if (((int)uVar5 < 1) || (1 << ((byte)local_41e & 0x1f) < (int)uVar5)) {
        uVar5 = 1 << ((byte)local_41e & 0x1f);
      }
      if (local_41e != 0x18) {
        if (local_42c == 0xc) {
          sVar2 = _fread(local_400,uVar5 * 3,1,param_1);
          if (sVar2 == 0) {
            FUN_1000cba0(10);
            return 0;
          }
          if (0 < (int)uVar5) {
            puVar4 = local_400 + 2;
            do {
              *puVar6 = *puVar4;
              uVar5 = uVar5 - 1;
              puVar6[1] = puVar4[-1];
              puVar6[2] = puVar4[-2];
              puVar4 = puVar4 + 3;
              puVar6 = puVar6 + 3;
            } while (uVar5 != 0);
          }
        }
        else {
          if (local_42c != 0x28) {
            FUN_1000cba0(0x46);
            return 0;
          }
          sVar2 = _fread(local_400,uVar5 * 4,1,param_1);
          if (sVar2 == 0) {
            FUN_1000cba0(10);
            return 0;
          }
          if (0 < (int)uVar5) {
            puVar4 = local_400 + 2;
            do {
              *puVar6 = *puVar4;
              uVar5 = uVar5 - 1;
              puVar6[1] = puVar4[-1];
              puVar6[2] = puVar4[-2];
              puVar4 = puVar4 + 4;
              puVar6 = puVar6 + 3;
            } while (uVar5 != 0);
          }
        }
      }
      iVar3 = _fseek(param_1,local_430,0);
      if (iVar3 == 0) {
        local_440 = (int)local_41e;
        iVar3 = local_428 * local_440 + 7;
        local_404 = ((int)(iVar3 + (iVar3 >> 0x1f & 7U)) >> 3) + 3U & 0xfffffffc;
        _DstBuf = (byte *)(**(code **)(PTR_DAT_1005b69c + 0x34c))((local_428 + 7 & 0xfffffff8) * 3);
        if (_DstBuf == (byte *)0x0) {
          FUN_1000cba0(3);
          local_424 = 0;
        }
        else {
          if ((local_41e == 8) &&
             (((*(uint *)(PTR_DAT_1005b69c + 0x20) == local_428 &&
               (((int)local_424 / *(int *)(PTR_DAT_1005b69c + 0x24)) *
                *(int *)(PTR_DAT_1005b69c + 0x24) - local_424 == 0)) ||
              ((*(uint *)(PTR_DAT_1005b69c + 700) != 0 &&
               ((local_428 == *(uint *)(PTR_DAT_1005b69c + 700) &&
                (((int)local_424 / *(int *)(PTR_DAT_1005b69c + 0x2c0)) *
                 *(int *)(PTR_DAT_1005b69c + 0x2c0) - local_424 == 0)))))))) {
            param_3 = param_3 & 0xfffffffe;
          }
          iVar3 = 0;
          if (0 < (int)local_424) {
            do {
              if ((local_41c == 0) || (local_41e == 0x18)) {
                sVar2 = _fread(_DstBuf,local_404,1,param_1);
                if (sVar2 == 0) {
                  (**(code **)(PTR_DAT_1005b69c + 0x358))(_DstBuf);
                  param_2[9] = 0;
                  FUN_1000cba0(10);
                  return 0;
                }
                FUN_10042b80(_DstBuf,local_428,local_440,param_2,param_3 | 4);
                iVar7 = FUN_10042f30((int)_DstBuf,local_428,local_424,iVar3,(int)param_2,param_3);
                if (iVar7 == 0) {
                  (**(code **)(PTR_DAT_1005b69c + 0x358))(_DstBuf);
                  param_2[9] = 0;
                  return 0;
                }
              }
              else {
                if (local_41c != 1) {
                  (**(code **)(PTR_DAT_1005b69c + 0x358))(_DstBuf);
                  param_2[9] = 0;
                  return 0;
                }
                iVar7 = 0;
                iStack_444 = 0;
                do {
                  sVar2 = _fread(&cStack_446,1,1,param_1);
                  if ((sVar2 == 0) || (sVar2 = _fread(&bStack_445,1,1,param_1), sVar2 == 0)) {
                    (**(code **)(PTR_DAT_1005b69c + 0x358))(_DstBuf);
                    param_2[9] = 0;
                    FUN_1000cba0(10);
                    return 0;
                  }
                  if (cStack_446 == '\0') {
                    if (bStack_445 < 3) {
                      if (bStack_445 == 0) {
                        iStack_444 = 1;
                      }
                      else {
                        if (bStack_445 != 1) {
                          if (bStack_445 == 2) {
                            (**(code **)(PTR_DAT_1005b69c + 0x358))();
                            param_2[9] = 0;
                            FUN_1000cba0(10);
                            return 0;
                          }
                          (**(code **)(PTR_DAT_1005b69c + 0x358))(_DstBuf);
                          param_2[9] = 0;
                          FUN_1000cba0(0x46);
                          return 0;
                        }
                        iStack_444 = 1;
                        iVar3 = local_424 - 1;
                      }
                    }
                    else {
                      sVar2 = _fread(_DstBuf + iVar7,(uint)bStack_445,1,param_1);
                      if (sVar2 == 0) {
                        (**(code **)(PTR_DAT_1005b69c + 0x358))(_DstBuf);
                        param_2[9] = 0;
                        FUN_1000cba0(10);
                        return 0;
                      }
                      iVar7 = iVar7 + (uint)bStack_445;
                      if (((bStack_445 & 1) != 0) &&
                         (sVar2 = _fread(&cStack_446,1,1,param_1), sVar2 == 0)) {
                        (**(code **)(PTR_DAT_1005b69c + 0x358))(_DstBuf);
                        param_2[9] = 0;
                        FUN_1000cba0(10);
                        return 0;
                      }
                    }
                  }
                  else {
                    while (bVar1 = cStack_446 != '\0', cStack_446 = cStack_446 + -1, bVar1) {
                      _DstBuf[iVar7] = bStack_445;
                      iVar7 = iVar7 + 1;
                    }
                  }
                } while (iStack_444 == 0);
                FUN_10042b80(_DstBuf,local_428,local_440,param_2,param_3);
                iVar7 = FUN_10042f30((int)_DstBuf,local_428,local_424,iVar3,(int)param_2,param_3);
                if (iVar7 == 0) {
                  (**(code **)(PTR_DAT_1005b69c + 0x358))(_DstBuf);
                  param_2[9] = 0;
                  return 0;
                }
              }
              iVar3 = iVar3 + 1;
            } while (iVar3 < (int)local_424);
          }
          (**(code **)(PTR_DAT_1005b69c + 0x358))(_DstBuf);
          local_424 = local_428 << 0x10 | local_424;
        }
      }
      else {
        FUN_1000cba0(10);
        local_424 = 0;
      }
    }
  }
  return local_424;
}


