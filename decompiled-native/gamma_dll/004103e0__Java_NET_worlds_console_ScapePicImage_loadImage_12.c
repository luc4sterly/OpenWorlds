// 004103e0 _Java_NET_worlds_console_ScapePicImage_loadImage@12 [Global]
// program: gamma.dll

void _Java_NET_worlds_console_ScapePicImage_loadImage_12
               (int *param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  LPCSTR pCVar2;
  undefined3 extraout_var;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined1 *puVar8;
  HBITMAP ho;
  undefined3 extraout_var_00;
  undefined4 *puVar9;
  CHAR local_6d8 [512];
  undefined **local_4d8;
  undefined4 *local_4d4;
  undefined **local_4cc [7];
  undefined4 local_4b0 [2];
  undefined *local_4a8;
  undefined **local_488 [16];
  int local_448;
  undefined4 local_444 [256];
  undefined4 *local_44 [13];
  
                    /* 0x103e0  66  _Java_NET_worlds_console_ScapePicImage_loadImage@12 */
  pCVar2 = (LPCSTR)(**(code **)(*param_1 + 0x2a4))(param_1,param_3,0);
  FUN_00411980(&local_4d8,1,pCVar2,0xc);
  if (*(char *)((int)local_4d4 + 0x32) == '\0') {
    FUN_00442fd0(&local_448,(int)&local_4d8);
    bVar1 = FUN_004431c0(&local_448);
    if (CONCAT31(extraout_var,bVar1) != 0) {
      iVar3 = FUN_00443160(&local_448);
      if (iVar3 != 0) {
        wsprintfA(local_6d8,s_ScapePicImage__s_cannot_use_tran_0046f0b0,pCVar2);
        (**(code **)(*param_1 + 0x2a8))(param_1,param_3,pCVar2);
        FUN_00443000(&local_448);
        local_4d4[0xf] = (int)local_488 - (int)local_4d4;
        local_4d8 = &PTR_FUN_0046f3e8;
        *local_4d4 = &PTR_LAB_0046f3f4;
        local_4d4[0xf] = (int)local_488 - (int)local_4d4;
        local_4cc[0] = &PTR_LAB_0046f3ac;
        if (((local_4a8 != &DAT_00482468) && (local_4a8 != &DAT_004824bc)) &&
           (local_4a8 != &DAT_00482510)) {
          FUN_004118d0((int *)local_4cc);
        }
        local_4cc[0] = &PTR_LAB_0046f370;
        FUN_00404dc0(local_4b0);
        local_4d8 = &PTR_LAB_0046f358;
        *local_4d4 = &PTR_LAB_0046f364;
        local_4d4[0xf] = (int)local_4cc - (int)local_4d4;
        local_488[0] = &PTR_LAB_0046f34c;
        FUN_00454d40(local_488);
        return;
      }
      iVar3 = FUN_00443080(&local_448);
      iVar4 = FUN_004430a0(&local_448);
      iVar5 = FUN_00443080(&local_448);
      uVar6 = iVar5 + 3U & 0xfffffffc;
      iVar5 = FUN_004430a0(&local_448);
      uVar7 = iVar5 + 1U & 0xfffffffe;
      puVar9 = local_444;
      puVar8 = (undefined1 *)FUN_00443140(&local_448);
      iVar5 = FUN_00443120(&local_448);
      FUN_00421e70(iVar5,puVar8,(int)puVar9);
      ho = FUN_00422260(uVar6,uVar7,local_444,local_44);
      bVar1 = FUN_00443180(&local_448,0,(int)local_44[0],uVar6);
      if (CONCAT31(extraout_var_00,bVar1) == 0) {
        DeleteObject(ho);
      }
      else {
        if (iVar4 < (int)uVar7) {
          FUN_0044ded0(local_44[0],(undefined4 *)((uVar7 - iVar4) * uVar6 + (int)local_44[0]),
                       uVar6 * iVar4);
        }
        (**(code **)(*param_1 + 0x1b4))(param_1,param_2,DAT_00489364,ho);
        (**(code **)(*param_1 + 0x1b4))(param_1,param_2,DAT_00489368,iVar3);
        (**(code **)(*param_1 + 0x1b4))(param_1,param_2,DAT_0048936c,iVar4);
      }
    }
    FUN_00443000(&local_448);
  }
  (**(code **)(*param_1 + 0x2a8))(param_1,param_3,pCVar2);
  local_4d4[0xf] = (int)local_488 - (int)local_4d4;
  local_4d8 = &PTR_FUN_0046f3e8;
  *local_4d4 = &PTR_LAB_0046f3f4;
  local_4d4[0xf] = (int)local_488 - (int)local_4d4;
  local_4cc[0] = &PTR_LAB_0046f3ac;
  if (((local_4a8 != &DAT_00482468) && (local_4a8 != &DAT_004824bc)) && (local_4a8 != &DAT_00482510)
     ) {
    FUN_004118d0((int *)local_4cc);
  }
  local_4cc[0] = &PTR_LAB_0046f370;
  FUN_00404dc0(local_4b0);
  local_4d8 = &PTR_LAB_0046f358;
  *local_4d4 = &PTR_LAB_0046f364;
  local_4d4[0xf] = (int)local_4cc - (int)local_4d4;
  local_488[0] = &PTR_LAB_0046f34c;
  FUN_00454d40(local_488);
  return;
}


