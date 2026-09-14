// 00455b40 FUN_00455b40 [Global]
// programa: gamma.dll

undefined * __cdecl FUN_00455b40(undefined4 param_1)

{
  int iVar1;
  undefined *puVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined *local_8;
  
  local_8 = (undefined *)0x0;
  if (DAT_0049eaf4 == 0) {
    uVar4 = FUN_00456470();
    DAT_0049eaf4 = (int)uVar4;
  }
  if (DAT_0049eaf4 == -1) {
    local_8 = (undefined *)0x0;
  }
  else {
    switch(param_1) {
    case 0:
      iVar1 = FUN_0044d760(&DAT_0049ea88,(byte *)s_AuthenticAMD_004826e8,0xc);
      if (iVar1 == 0) {
        local_8 = (undefined *)0x1;
      }
      else {
        iVar1 = FUN_0044d760(&DAT_0049ea88,(byte *)s_GenuineIntel_004826d8,0xc);
        if (iVar1 == 0) {
          local_8 = (undefined *)0x2;
        }
        else {
          iVar1 = FUN_0044d760(&DAT_0049ea88,(byte *)s_CyrixInstead_004826c8,0xc);
          if (iVar1 == 0) {
            local_8 = (undefined *)0x3;
          }
          else {
            iVar1 = FUN_0044d760(&DAT_0049ea88,(byte *)s_CentaurHauls_004826b8,0xc);
            if (iVar1 == 0) {
              local_8 = (undefined *)0x4;
            }
            else {
              local_8 = (undefined *)0x0;
            }
          }
        }
      }
      break;
    case 1:
      local_8 = (undefined *)0x0;
      puVar2 = FUN_00455b40(0);
      switch(puVar2) {
      case (undefined *)0x1:
        uVar3 = DAT_0049ead0 >> 8 & 0xf;
        if (uVar3 == 4) {
          local_8 = (undefined *)0x1;
        }
        else if (uVar3 == 5) {
          switch(DAT_0049ead0 >> 4 & 0xf) {
          case 0:
          case 1:
          case 2:
          case 3:
            local_8 = (undefined *)0x2;
            break;
          case 4:
          case 5:
          case 6:
          case 7:
            local_8 = (undefined *)0x3;
            break;
          case 8:
            local_8 = (undefined *)0x4;
            break;
          case 9:
          case 10:
          case 0xb:
          case 0xc:
          case 0xd:
          case 0xe:
          case 0xf:
            local_8 = (undefined *)0x5;
          }
        }
        else if (uVar3 == 6) {
          local_8 = (undefined *)0x6;
        }
        break;
      case (undefined *)0x2:
        uVar3 = DAT_0049ead0 >> 8 & 0xf;
        if (uVar3 == 4) {
          switch(DAT_0049ead0 >> 4 & 0xf) {
          case 0:
            local_8 = (undefined *)0x7;
            break;
          case 1:
            local_8 = (undefined *)0x7;
            break;
          case 2:
            local_8 = (undefined *)0x8;
            break;
          case 3:
            local_8 = (undefined *)0x9;
            break;
          case 4:
            local_8 = (undefined *)0xa;
            break;
          case 5:
            local_8 = (undefined *)0xb;
            break;
          case 7:
            local_8 = (undefined *)0xc;
            break;
          case 8:
            local_8 = (undefined *)0xd;
          }
        }
        else if (uVar3 == 5) {
          switch(DAT_0049ead0 >> 4 & 0xf) {
          case 1:
            local_8 = (undefined *)0xe;
            break;
          case 2:
            local_8 = (undefined *)0xe;
            break;
          case 3:
            local_8 = (undefined *)0xe;
            break;
          case 4:
            local_8 = (undefined *)0xf;
          }
        }
        else if (uVar3 == 6) {
          switch(DAT_0049ead0 >> 4 & 0xf) {
          case 1:
            local_8 = (undefined *)0x10;
            break;
          case 3:
            local_8 = (undefined *)0x11;
            break;
          case 5:
            local_8 = (undefined *)0x11;
            break;
          case 6:
            local_8 = (undefined *)0x12;
            break;
          case 7:
            local_8 = (undefined *)0x13;
          }
        }
        break;
      case (undefined *)0x3:
        local_8 = (undefined *)0x0;
        break;
      case (undefined *)0x4:
        local_8 = (undefined *)0x0;
      }
      break;
    case 2:
      local_8 = &DAT_0049ea88;
      break;
    case 3:
      local_8 = &DAT_0049ea98;
      break;
    case 4:
      local_8 = (undefined *)0x1;
      break;
    case 5:
      local_8 = (undefined *)(DAT_0049eac8 & 1);
      break;
    case 6:
      local_8 = (undefined *)(DAT_0049eac8 >> 1 & 1);
      break;
    case 7:
      local_8 = (undefined *)(DAT_0049eac8 >> 2 & 1);
      break;
    case 8:
      local_8 = (undefined *)(DAT_0049eac8 >> 3 & 1);
      break;
    case 9:
      local_8 = (undefined *)(DAT_0049eac8 >> 4 & 1);
      break;
    case 10:
      local_8 = (undefined *)(DAT_0049eac8 >> 5 & 1);
      break;
    case 0xb:
      local_8 = (undefined *)(DAT_0049eac8 >> 6 & 1);
      break;
    case 0xc:
      local_8 = (undefined *)(DAT_0049eac8 >> 7 & 1);
      break;
    case 0xd:
      local_8 = (undefined *)(DAT_0049eac8 >> 8 & 1);
      break;
    case 0xe:
      local_8 = (undefined *)(DAT_0049eac8 >> 9 & 1);
      break;
    case 0xf:
      local_8 = (undefined *)(DAT_0049eac8 >> 0xb & 1);
      break;
    case 0x10:
      local_8 = (undefined *)(DAT_0049eac8 >> 0xc & 1);
      break;
    case 0x11:
      local_8 = (undefined *)(DAT_0049eac8 >> 0xd & 1);
      break;
    case 0x12:
      local_8 = (undefined *)(DAT_0049eac8 >> 0xe & 1);
      break;
    case 0x13:
      local_8 = (undefined *)(DAT_0049eac8 >> 0xf & 1);
      break;
    case 0x14:
      local_8 = (undefined *)(DAT_0049eac8 >> 0x10 & 1);
      break;
    case 0x15:
      local_8 = (undefined *)(DAT_0049eac8 >> 0x11 & 1);
      break;
    case 0x16:
      local_8 = (undefined *)(DAT_0049eac8 >> 0x19 & 1 | DAT_0049eacc >> 0x16 & 1);
      break;
    case 0x17:
      local_8 = (undefined *)(DAT_0049eac8 >> 0x17 & 1);
      break;
    case 0x18:
      local_8 = (undefined *)(DAT_0049eac8 >> 0x18 & 1);
      break;
    case 0x19:
      local_8 = (undefined *)(DAT_0049eacc >> 0x1e & 1);
      break;
    case 0x1a:
      local_8 = (undefined *)(DAT_0049eacc >> 0x1f);
      break;
    case 0x1b:
      local_8 = (undefined *)(DAT_0049eacc >> 0x16 & 1);
      break;
    case 0x1c:
      local_8 = (undefined *)(DAT_0049eac8 >> 0x19 & 1);
      break;
    case 0x1d:
      puVar2 = FUN_00455b40(0x1c);
      local_8 = (undefined *)(uint)(puVar2 != (undefined *)0x0);
      break;
    default:
      puVar2 = FUN_00455b40(0);
      if (puVar2 == (undefined *)0x1) {
        switch(param_1) {
        case 0x1e:
          local_8 = (undefined *)(DAT_0049ead8 >> 0x18);
          break;
        case 0x1f:
          local_8 = (undefined *)(DAT_0049ead8 >> 0x10 & 0xff);
          break;
        case 0x20:
          local_8 = (undefined *)(DAT_0049ead8 >> 8 & 0xff);
          break;
        case 0x21:
          local_8 = (undefined *)(DAT_0049ead8 & 0xff);
          break;
        case 0x26:
          local_8 = (undefined *)(DAT_0049eadc >> 0x18);
          break;
        case 0x27:
          local_8 = (undefined *)(DAT_0049eadc >> 0x10 & 0xff);
          break;
        case 0x28:
          local_8 = (undefined *)(DAT_0049eadc >> 8 & 0xff);
          break;
        case 0x29:
          local_8 = (undefined *)(DAT_0049eadc & 0xff);
          break;
        case 0x2a:
          local_8 = (undefined *)(DAT_0049eae0 >> 0x18);
          break;
        case 0x2b:
          local_8 = (undefined *)(DAT_0049eae0 >> 0x10 & 0xff);
          break;
        case 0x2c:
          local_8 = (undefined *)(DAT_0049eae0 >> 8 & 0xff);
          break;
        case 0x2d:
          local_8 = (undefined *)(DAT_0049eae0 & 0xff);
          break;
        case 0x2e:
          local_8 = (undefined *)(DAT_0049eaec >> 0x10);
          break;
        case 0x2f:
          local_8 = (undefined *)(DAT_0049eaec >> 0xc & 0xf);
          break;
        case 0x30:
          local_8 = (undefined *)(DAT_0049eaec >> 8 & 0xf);
          break;
        case 0x31:
          local_8 = (undefined *)(DAT_0049eaec & 0xff);
        }
        puVar2 = FUN_00455b40(1);
        if (puVar2 == (undefined *)0x6) {
          switch(param_1) {
          case 0x22:
            local_8 = (undefined *)(DAT_0049ead4 >> 0x18);
            break;
          case 0x23:
            local_8 = (undefined *)(DAT_0049ead4 >> 0x10 & 0xff);
            break;
          case 0x24:
            local_8 = (undefined *)(DAT_0049ead4 >> 8 & 0xff);
            break;
          case 0x25:
            local_8 = (undefined *)(DAT_0049ead4 & 0xff);
            break;
          case 0x32:
            local_8 = (undefined *)(DAT_0049eae4 >> 0x1c);
            break;
          case 0x33:
            local_8 = (undefined *)(DAT_0049eae4 >> 0x10 & 0xfff);
            break;
          case 0x34:
            local_8 = (undefined *)(DAT_0049eae4 >> 0xc & 0xf);
            break;
          case 0x35:
            local_8 = (undefined *)(DAT_0049eae4 & 0xfff);
            break;
          case 0x36:
            local_8 = (undefined *)(DAT_0049eae8 >> 0x1c);
            break;
          case 0x37:
            local_8 = (undefined *)(DAT_0049eae8 >> 0x10 & 0xfff);
            break;
          case 0x38:
            local_8 = (undefined *)(DAT_0049eae8 >> 0xc & 0xf);
            break;
          case 0x39:
            local_8 = (undefined *)(DAT_0049eae8 & 0xfff);
          }
        }
      }
    }
  }
  return local_8;
}


