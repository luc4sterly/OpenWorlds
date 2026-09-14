// 00401de0 _Java_NET_worlds_core_FastDataInput_readUTF@8 [Global]
// programa: gamma.dll

undefined4 _Java_NET_worlds_core_FastDataInput_readUTF_8(int *param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  undefined1 *puVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int local_38;
  uint local_34;
  undefined4 local_30;
  int local_2c;
  uint local_28;
  undefined4 local_20;
  undefined4 local_16;
  byte local_12;
  byte local_11;
  
                    /* 0x1de0  131  _Java_NET_worlds_core_FastDataInput_readUTF@8 */
  iVar5 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_00489024);
  iVar6 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_00489024);
  if (*(int *)(iVar6 + 8) < 2) {
    if (*(int *)(iVar6 + 0xc) == 0) {
      *(char **)(iVar6 + 0xc) = s_java_io_EOFException_0046d18c;
      *(char **)(iVar6 + 0x10) = s_EOF_Error_0046d1a4;
    }
  }
  else {
    local_16._0_2_ = CONCAT11(**(undefined1 **)(iVar6 + 4),*(undefined1 *)(*(int *)(iVar6 + 4) + 1))
    ;
    *(int *)(iVar6 + 4) = *(int *)(iVar6 + 4) + 2;
    *(int *)(iVar6 + 8) = *(int *)(iVar6 + 8) + -2;
  }
  if (*(byte **)(iVar6 + 0xc) != (byte *)0x0) {
    FUN_00402930(param_1,*(byte **)(iVar6 + 0xc),*(undefined4 *)(iVar6 + 0x10));
  }
  uVar1 = local_16 & 0xffff;
  if (*(int *)(iVar5 + 0xc) != 0) {
    return 0;
  }
  uVar7 = (**(code **)(*param_1 + 0x2c4))(param_1,uVar1);
  iVar6 = (**(code **)(*param_1 + 0x2e4))(param_1,uVar7,0);
  local_2c = 0;
  local_28 = 0;
  if (uVar1 != 0) {
    while( true ) {
      iVar8 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_00489024);
      if (*(int *)(iVar8 + 8) < 1) {
        if (*(int *)(iVar8 + 0xc) == 0) {
          *(char **)(iVar8 + 0xc) = s_java_io_EOFException_0046d18c;
          *(char **)(iVar8 + 0x10) = s_EOF_Error_0046d1a4;
        }
      }
      else {
        puVar3 = *(undefined1 **)(iVar8 + 4);
        *(int *)(iVar8 + 4) = *(int *)(iVar8 + 4) + 1;
        local_16 = (uint)CONCAT11(local_16._3_1_,*puVar3) << 0x10;
        *(int *)(iVar8 + 8) = *(int *)(iVar8 + 8) + -1;
      }
      if (*(byte **)(iVar8 + 0xc) != (byte *)0x0) {
        FUN_00402930(param_1,*(byte **)(iVar8 + 0xc),*(undefined4 *)(iVar8 + 0x10));
      }
      local_34 = (uint)local_16._2_1_;
      if (*(int *)(iVar5 + 0xc) != 0) break;
      uVar2 = local_28 + 1;
      switch((int)local_34 >> 4) {
      case 0:
      case 1:
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
      case 7:
        local_34._0_2_ = (ushort)local_16._2_1_;
        *(ushort *)(iVar6 + local_2c * 2) = (ushort)local_34;
        local_2c = local_2c + 1;
        local_28 = local_28 + 1;
        break;
      default:
switchD_00401f63_caseD_8:
        local_28 = uVar2;
        iVar8 = 0;
        goto LAB_00402172;
      case 0xc:
      case 0xd:
        uVar2 = local_28 + 2;
        if ((int)uVar1 < (int)uVar2) goto switchD_00401f63_caseD_8;
        iVar8 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_00489024);
        if (*(int *)(iVar8 + 8) < 1) {
          if (*(int *)(iVar8 + 0xc) == 0) {
            *(char **)(iVar8 + 0xc) = s_java_io_EOFException_0046d18c;
            *(char **)(iVar8 + 0x10) = s_EOF_Error_0046d1a4;
          }
        }
        else {
          puVar3 = *(undefined1 **)(iVar8 + 4);
          *(int *)(iVar8 + 4) = *(int *)(iVar8 + 4) + 1;
          local_16 = CONCAT13(*puVar3,(undefined3)local_16);
          *(int *)(iVar8 + 8) = *(int *)(iVar8 + 8) + -1;
        }
        if (*(byte **)(iVar8 + 0xc) != (byte *)0x0) {
          FUN_00402930(param_1,*(byte **)(iVar8 + 0xc),*(undefined4 *)(iVar8 + 0x10));
        }
        local_28 = uVar2;
        if ((local_16 >> 0x18 & 0xc0) == 0x80) {
          local_34._0_1_ = (byte)((local_34 & 0x1f) << 6) | (byte)(local_16 >> 0x18) & 0x3f;
          *(short *)(iVar6 + local_2c * 2) = (short)(char)(byte)local_34;
          local_2c = local_2c + 1;
        }
        else if (*(int *)(iVar5 + 0xc) == 0) {
          *(char **)(iVar5 + 0xc) = s_java_io_UTFDataFormatException_0046d1b0;
          *(char **)(iVar5 + 0x10) = s_UTF_Format_Error_0046d1d0;
        }
        break;
      case 0xe:
        local_28 = local_28 + 3;
        uVar2 = local_28;
        if ((int)uVar1 < (int)local_28) goto switchD_00401f63_caseD_8;
        iVar8 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_00489024);
        if (*(int *)(iVar8 + 8) < 1) {
          if (*(int *)(iVar8 + 0xc) == 0) {
            *(char **)(iVar8 + 0xc) = s_java_io_EOFException_0046d18c;
            *(char **)(iVar8 + 0x10) = s_EOF_Error_0046d1a4;
          }
        }
        else {
          pbVar4 = *(byte **)(iVar8 + 4);
          *(int *)(iVar8 + 4) = *(int *)(iVar8 + 4) + 1;
          local_12 = *pbVar4;
          *(int *)(iVar8 + 8) = *(int *)(iVar8 + 8) + -1;
        }
        if (*(byte **)(iVar8 + 0xc) != (byte *)0x0) {
          FUN_00402930(param_1,*(byte **)(iVar8 + 0xc),*(undefined4 *)(iVar8 + 0x10));
        }
        iVar8 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_00489024);
        if (*(int *)(iVar8 + 8) < 1) {
          if (*(int *)(iVar8 + 0xc) == 0) {
            *(char **)(iVar8 + 0xc) = s_java_io_EOFException_0046d18c;
            *(char **)(iVar8 + 0x10) = s_EOF_Error_0046d1a4;
          }
        }
        else {
          pbVar4 = *(byte **)(iVar8 + 4);
          *(int *)(iVar8 + 4) = *(int *)(iVar8 + 4) + 1;
          local_11 = *pbVar4;
          *(int *)(iVar8 + 8) = *(int *)(iVar8 + 8) + -1;
        }
        if (*(byte **)(iVar8 + 0xc) != (byte *)0x0) {
          FUN_00402930(param_1,*(byte **)(iVar8 + 0xc),*(undefined4 *)(iVar8 + 0x10));
        }
        if (((local_12 & 0xc0) == 0x80) && ((local_11 & 0xc0) == 0x80)) {
          *(short *)(iVar6 + local_2c * 2) = (short)(char)(local_12 << 6 | local_11 & 0x3f);
          local_2c = local_2c + 1;
          break;
        }
        iVar8 = *(int *)(iVar5 + 0xc);
LAB_00402172:
        if (iVar8 == 0) {
          *(char **)(iVar5 + 0xc) = s_java_io_UTFDataFormatException_0046d1b0;
          *(char **)(iVar5 + 0x10) = s_UTF_Format_Error_0046d1d0;
        }
      }
      if ((*(int *)(iVar5 + 0xc) != 0) || ((int)uVar1 <= (int)local_28)) break;
    }
  }
  local_30 = 0;
  local_38 = iVar6;
  local_20 = uVar7;
  if (*(int *)(iVar5 + 0xc) == 0) {
    if (local_28 != uVar1) {
      FUN_00402800(s_nFastDataInput_0046d204,0x1e9);
      return 0;
    }
    if (local_2c < (int)uVar1) {
      local_20 = (**(code **)(*param_1 + 0x2c4))(param_1,local_2c);
      local_38 = (**(code **)(*param_1 + 0x2e4))(param_1,local_20,0);
      iVar8 = 0;
      if (0 < local_2c) {
        if (8 < local_2c) {
          do {
            *(undefined2 *)(local_38 + iVar8 * 2) = *(undefined2 *)(iVar6 + iVar8 * 2);
            *(undefined2 *)(local_38 + 2 + iVar8 * 2) = *(undefined2 *)(iVar6 + 2 + iVar8 * 2);
            *(undefined2 *)(local_38 + 4 + iVar8 * 2) = *(undefined2 *)(iVar6 + 4 + iVar8 * 2);
            *(undefined2 *)(local_38 + 6 + iVar8 * 2) = *(undefined2 *)(iVar6 + 6 + iVar8 * 2);
            *(undefined2 *)(local_38 + 8 + iVar8 * 2) = *(undefined2 *)(iVar6 + 8 + iVar8 * 2);
            *(undefined2 *)(local_38 + 10 + iVar8 * 2) = *(undefined2 *)(iVar6 + 10 + iVar8 * 2);
            *(undefined2 *)(local_38 + 0xc + iVar8 * 2) = *(undefined2 *)(iVar6 + 0xc + iVar8 * 2);
            *(undefined2 *)(local_38 + 0xe + iVar8 * 2) = *(undefined2 *)(iVar6 + 0xe + iVar8 * 2);
            iVar8 = iVar8 + 8;
          } while (iVar8 < local_2c + -8);
        }
        for (; iVar8 < local_2c; iVar8 = iVar8 + 1) {
          *(undefined2 *)(local_38 + iVar8 * 2) = *(undefined2 *)(iVar6 + iVar8 * 2);
        }
      }
      (**(code **)(*param_1 + 0x304))(param_1,uVar7,iVar6,0);
    }
    local_30 = (**(code **)(*param_1 + 0x28c))(param_1,local_38,local_2c);
  }
  (**(code **)(*param_1 + 0x304))(param_1,local_20,local_38,0);
  if (*(byte **)(iVar5 + 0xc) != (byte *)0x0) {
    FUN_00402930(param_1,*(byte **)(iVar5 + 0xc),*(undefined4 *)(iVar5 + 0x10));
  }
  return local_30;
}


