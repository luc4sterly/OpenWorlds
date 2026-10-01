// 00422b30 FUN_00422b30 [Global]
// program: gamma.dll

undefined1 * __cdecl
FUN_00422b30(int *param_1,undefined4 param_2,undefined4 param_3,int param_4,int *param_5,
            int *param_6,int *param_7)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  bool bVar7;
  char *pcVar8;
  undefined4 uVar9;
  int iVar10;
  undefined4 *puVar11;
  int iVar12;
  undefined3 extraout_var;
  int iVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
  byte *pbVar18;
  int iVar19;
  HDC hdc;
  HBITMAP ho;
  undefined3 extraout_var_00;
  uint uVar20;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar21;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar22;
  undefined1 *puVar23;
  undefined1 *local_4e4;
  int local_4c4;
  int local_4b0;
  undefined4 local_4ac;
  undefined ***local_4a8;
  undefined1 auStack_4a0 [52];
  undefined **local_46c [16];
  int local_42c;
  byte local_428 [1024];
  undefined4 *local_28 [2];
  undefined4 *local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  local_4e4 = (undefined1 *)0x0;
  pcVar8 = (char *)(**(code **)(*param_1 + 0x2a4))(param_1,param_2,0);
  uVar9 = (**(code **)(*param_1 + 0x2a4))(param_1,param_3,0);
  iVar10 = FUN_00403ff0(param_1);
  if (iVar10 != 0) {
    puVar11 = (undefined4 *)(**(code **)(*param_1 + 0x2e0))(param_1,iVar10,0);
    iVar12 = (**(code **)(*param_1 + 0x2ac))(param_1,iVar10);
    FUN_00424260(&local_4b0,puVar11,iVar12);
    local_20 = &local_4ac;
    local_4a8 = local_46c;
    local_46c[0] = &PTR_LAB_0046f34c;
    FUN_00411ef0(local_20,0,(int)auStack_4a0);
    *local_20 = &PTR_FUN_00471860;
    *(undefined ***)local_20[1] = &PTR_LAB_0047186c;
    *(int *)(local_20[1] + 0x3c) = (int)local_20 + (0x40 - local_20[1]);
    FUN_004240f0(local_20 + 3,&local_4b0,8);
    FUN_00442fd0(&local_42c,(int)&local_4ac);
    bVar7 = FUN_004431c0(&local_42c);
    if (CONCAT31(extraout_var,bVar7) != 0) {
      iVar12 = FUN_00443160(&local_42c);
      if (iVar12 == 0) {
        local_4c4 = -1;
      }
      else {
        local_4c4 = 0xff;
      }
      iVar12 = FUN_00443100(&local_42c);
      if (param_4 < iVar12) {
        iVar12 = param_4;
      }
      iVar13 = FUN_00443080(&local_42c);
      iVar14 = FUN_004430a0(&local_42c);
      iVar15 = FUN_00443080(&local_42c);
      uVar16 = iVar15 + 3U & 0xfffffffc;
      iVar15 = FUN_004430a0(&local_42c);
      uVar17 = iVar15 + 1U & 0xfffffffe;
      if (param_5 != (int *)0x0) {
        *param_5 = iVar12;
      }
      if (param_6 != (int *)0x0) {
        iVar15 = FUN_004430c0(&local_42c);
        *param_6 = iVar15;
      }
      if (param_7 != (int *)0x0) {
        iVar15 = FUN_004430e0(&local_42c);
        *param_7 = iVar15;
      }
      uVar20 = iVar12 * 4;
      local_4e4 = (undefined1 *)FUN_00450b60(uVar20);
      puVar23 = local_4e4;
      if (local_4e4 == (undefined1 *)0x0) {
        FUN_00402800(s_nScapePicTexture_004713c4,0x1c7);
      }
      for (; uVar20 != 0; uVar20 = uVar20 - 1) {
        *puVar23 = 0;
        puVar23 = puVar23 + 1;
      }
      pbVar18 = (byte *)FUN_00443140(&local_42c);
      iVar19 = FUN_00443120(&local_42c);
      iVar15 = 0;
      if (0 < iVar19) {
        if (8 < iVar19) {
          do {
            local_428[iVar15 * 4 + 2] = *pbVar18;
            local_428[iVar15 * 4 + 1] = pbVar18[1];
            local_428[iVar15 * 4] = pbVar18[2];
            local_428[iVar15 * 4 + 3] = 0;
            local_428[iVar15 * 4 + 6] = pbVar18[4];
            local_428[iVar15 * 4 + 5] = pbVar18[5];
            local_428[iVar15 * 4 + 4] = pbVar18[6];
            local_428[iVar15 * 4 + 7] = 0;
            local_428[iVar15 * 4 + 10] = pbVar18[8];
            local_428[iVar15 * 4 + 9] = pbVar18[9];
            local_428[iVar15 * 4 + 8] = pbVar18[10];
            local_428[iVar15 * 4 + 0xb] = 0;
            local_428[iVar15 * 4 + 0xe] = pbVar18[0xc];
            local_428[iVar15 * 4 + 0xd] = pbVar18[0xd];
            local_428[iVar15 * 4 + 0xc] = pbVar18[0xe];
            local_428[iVar15 * 4 + 0xf] = 0;
            local_428[iVar15 * 4 + 0x12] = pbVar18[0x10];
            local_428[iVar15 * 4 + 0x11] = pbVar18[0x11];
            local_428[iVar15 * 4 + 0x10] = pbVar18[0x12];
            local_428[iVar15 * 4 + 0x13] = 0;
            local_428[iVar15 * 4 + 0x16] = pbVar18[0x14];
            local_428[iVar15 * 4 + 0x15] = pbVar18[0x15];
            local_428[iVar15 * 4 + 0x14] = pbVar18[0x16];
            local_428[iVar15 * 4 + 0x17] = 0;
            local_428[iVar15 * 4 + 0x1a] = pbVar18[0x18];
            local_428[iVar15 * 4 + 0x19] = pbVar18[0x19];
            local_428[iVar15 * 4 + 0x18] = pbVar18[0x1a];
            local_428[iVar15 * 4 + 0x1b] = 0;
            local_428[iVar15 * 4 + 0x1e] = pbVar18[0x1c];
            local_428[iVar15 * 4 + 0x1d] = pbVar18[0x1d];
            local_428[iVar15 * 4 + 0x1c] = pbVar18[0x1e];
            local_428[iVar15 * 4 + 0x1f] = 0;
            iVar15 = iVar15 + 8;
            pbVar18 = pbVar18 + 0x20;
          } while (iVar15 < iVar19 + -8);
        }
        for (; iVar15 < iVar19; iVar15 = iVar15 + 1) {
          local_428[iVar15 * 4 + 2] = *pbVar18;
          local_428[iVar15 * 4 + 1] = pbVar18[1];
          local_428[iVar15 * 4] = pbVar18[2];
          local_428[iVar15 * 4 + 3] = 0;
          pbVar18 = pbVar18 + 4;
        }
      }
      local_1c = DAT_004714a8;
      uVar21 = local_1c;
      if (iVar15 < 0x100) {
        pbVar18 = local_428 + iVar15 * 4;
        local_1c._1_1_ = (byte)((uint)DAT_004714a8 >> 8);
        bVar1 = local_1c._1_1_;
        local_1c._3_1_ = (byte)((uint)DAT_004714a8 >> 0x18);
        bVar3 = local_1c._3_1_;
        local_1c._2_1_ = (byte)((uint)DAT_004714a8 >> 0x10);
        bVar2 = local_1c._2_1_;
        local_1c = uVar21;
        do {
          iVar15 = iVar15 + 1;
          *pbVar18 = (byte)local_1c;
          pbVar18[1] = bVar1;
          pbVar18[2] = bVar2;
          pbVar18[3] = bVar3;
          pbVar18 = pbVar18 + 4;
        } while (iVar15 < 0x100);
      }
      iVar15 = FUN_00417900();
      if (iVar15 == 2) {
        local_18 = DAT_004714f4;
        uVar21 = local_18;
        local_18._1_1_ = (byte)((uint)DAT_004714f4 >> 8);
        bVar1 = local_18._1_1_;
        local_18._2_1_ = (byte)((uint)DAT_004714f4 >> 0x10);
        bVar2 = local_18._2_1_;
        local_18._3_1_ = (byte)((uint)DAT_004714f4 >> 0x18);
        bVar3 = local_18._3_1_;
        local_14 = DAT_0049d1e1;
        uVar22 = local_14;
        local_14._1_1_ = (byte)((uint)DAT_0049d1e1 >> 8);
        bVar4 = local_14._1_1_;
        iVar15 = 0;
        local_14._3_1_ = (byte)((uint)DAT_0049d1e1 >> 0x18);
        bVar6 = local_14._3_1_;
        pbVar18 = local_428;
        local_14._2_1_ = (byte)((uint)DAT_0049d1e1 >> 0x10);
        bVar5 = local_14._2_1_;
        local_18 = uVar21;
        local_14 = uVar22;
        do {
          if (iVar15 == local_4c4) {
            *pbVar18 = (byte)local_14;
            pbVar18[1] = bVar4;
            pbVar18[2] = bVar5;
            pbVar18[3] = bVar6;
          }
          else if (((pbVar18[2] < 0xc) && (pbVar18[1] < 6)) && (*pbVar18 < 0xc)) {
            *pbVar18 = (byte)local_18;
            pbVar18[1] = bVar1;
            pbVar18[2] = bVar2;
            pbVar18[3] = bVar3;
          }
          iVar15 = iVar15 + 1;
          pbVar18 = pbVar18 + 4;
        } while (iVar15 < 0x100);
      }
      hdc = CreateCompatibleDC((HDC)0x0);
      if (&stack0x00000000 == (undefined1 *)0x428) {
        iVar15 = 4;
      }
      else {
        iVar15 = 1;
      }
      ho = FUN_00422150(hdc,uVar16,uVar17,(undefined4 *)local_428,local_28,iVar15,0);
      DeleteDC(hdc);
      if (ho == (HBITMAP)0x0) {
        FUN_004028c0((byte *)s_Out_of_virtual_memory_004714b0,(byte *)s_makeTextures2_004714f8);
      }
      uVar20 = 0;
      if (0 < iVar12) {
        do {
          bVar7 = FUN_00443180(&local_42c,uVar20,(int)local_28[0],uVar16);
          if (CONCAT31(extraout_var_00,bVar7) != 0) {
            uVar21 = extraout_ECX;
            uVar22 = extraout_EDX;
            if (iVar14 < (int)uVar17) {
              FUN_0044ded0(local_28[0],(undefined4 *)((int)local_28[0] + (uVar17 - iVar14) * uVar16)
                           ,uVar16 * iVar14);
              uVar21 = extraout_ECX_00;
              uVar22 = extraout_EDX_00;
            }
            iVar15 = FUN_004222b0(uVar21,uVar22,ho,iVar13,iVar14,local_4c4,pcVar8,uVar20);
            *(int *)(local_4e4 + uVar20 * 4) = iVar15;
          }
          uVar20 = uVar20 + 1;
        } while ((int)uVar20 < iVar12);
      }
      DeleteObject(ho);
    }
    (**(code **)(*param_1 + 0x300))(param_1,iVar10,puVar11,0);
    FUN_00443000(&local_42c);
    local_4a8[0xf] = (undefined **)((int)local_46c - (int)local_4a8);
    FUN_004231d0(&local_4ac);
    FUN_004108d0(local_46c);
    FUN_00404ed0(&local_4b0);
  }
  (**(code **)(*param_1 + 0x2a8))(param_1,param_2,pcVar8);
  (**(code **)(*param_1 + 0x2a8))(param_1,param_3,uVar9);
  return local_4e4;
}


