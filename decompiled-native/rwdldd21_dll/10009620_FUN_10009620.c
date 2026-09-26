// 10009620 FUN_10009620 [Global]
// programa: RWDLDD21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10009620(int param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if (0 < param_1) {
    do {
      uVar1 = *param_2;
      uVar3 = uVar1 & 0x7fffffff;
      if (uVar3 < 0x3e9) {
        if (uVar3 == 1000) {
          *param_2 = uVar1 | 0x80000000;
        }
        else if (uVar3 == 1) {
          *param_2 = uVar1 | 0x80000000;
        }
        else if (uVar3 == 2) {
          DAT_100360ac = param_2[1];
          *param_2 = *param_2 | 0x80000000;
        }
        goto switchD_1000966e_caseD_3ed;
      }
      uVar2 = DAT_100360a0;
      switch(uVar3) {
      case 0x3e9:
        *param_2 = uVar1 | 0x80000000;
        break;
      case 0x3ea:
        _DAT_100360b4 = param_2[1];
        *param_2 = *param_2 | 0x80000000;
        break;
      case 0x3eb:
        DAT_100360b8 = param_2[1];
        if ((int)DAT_100360b8 < 0) {
          DAT_100360b8 = 0xffffffff;
        }
        else if (0 < (int)DAT_100360b8) {
          DAT_100360b8 = 1;
        }
        goto LAB_100096f2;
      case 0x3ec:
        uVar2 = param_2[1];
        if ((uVar2 == 0x10) || (uVar2 == 0x20)) goto LAB_100096f2;
        break;
      case 0x3ee:
        DAT_100360b0 = 1;
LAB_100096f2:
        DAT_100360a0 = uVar2;
        *param_2 = *param_2 | 0x80000000;
      }
switchD_1000966e_caseD_3ed:
      param_2 = param_2 + 2;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  return;
}


