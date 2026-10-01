// 10003f00 FUN_10003f00 [Global]
// program: RWDL6D21.DLL

void FUN_10003f00(int param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  
  if (0 < param_1) {
    do {
      uVar2 = *param_2 & 0x7fffffff;
      uVar1 = DAT_10079054;
      if (uVar2 < 0x3e9) {
        if (uVar2 == 1000) {
          DAT_1007903c = 1;
          goto LAB_10003fd6;
        }
        if (uVar2 == 1) {
          *param_2 = *param_2 | 0x80000000;
        }
        else if (uVar2 == 2) {
          DAT_10079068 = param_2[1];
          *param_2 = *param_2 | 0x80000000;
        }
        goto switchD_10003f4e_default;
      }
      switch(uVar2) {
      case 0x3ea:
        DAT_1007906c = param_2[1];
        *param_2 = *param_2 | 0x80000000;
        goto switchD_10003f4e_default;
      case 0x3eb:
        DAT_10079070 = param_2[1];
        if ((int)DAT_10079070 < 0) {
          DAT_10079070 = 0xffffffff;
        }
        else if (0 < (int)DAT_10079070) {
          DAT_10079070 = 1;
        }
        break;
      case 0x3ec:
        uVar1 = param_2[1];
        if ((uVar1 == 8) || (uVar1 == 0x10)) break;
        goto switchD_10003f4e_default;
      case 0x3ed:
        DAT_10079048 = 1;
        break;
      case 0x3ee:
        DAT_10079050 = 1;
        break;
      case 0x3ef:
        DAT_10079040 = 1;
        break;
      default:
        goto switchD_10003f4e_default;
      }
LAB_10003fd6:
      DAT_10079054 = uVar1;
      *param_2 = *param_2 | 0x80000000;
switchD_10003f4e_default:
      param_2 = param_2 + 2;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  return;
}


