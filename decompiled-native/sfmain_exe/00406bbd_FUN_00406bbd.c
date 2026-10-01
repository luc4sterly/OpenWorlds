// 00406bbd FUN_00406bbd [Global]
// program: sfmain.exe

void __fastcall FUN_00406bbd(undefined4 param_1,short *param_2)

{
  ushort uVar1;
  uint uVar2;
  byte *unaff_EBX;
  undefined4 unaff_ESI;
  byte local_a0 [2];
  undefined2 uStack_9e;
  char local_9c;
  undefined1 uStack_9b;
  undefined1 local_9a;
  undefined1 local_98;
  char local_96;
  byte bStack_94;
  short local_92;
  byte bStack_90;
  undefined2 local_8e;
  char cStack_8c;
  undefined1 uStack_8b;
  undefined1 local_8a;
  undefined1 local_88;
  byte local_86;
  undefined2 uStack_84;
  char local_82;
  undefined1 uStack_81;
  undefined1 local_80;
  undefined1 local_7e;
  char local_7c;
  byte bStack_7a;
  short local_78;
  byte bStack_76;
  undefined2 local_74;
  char cStack_72;
  undefined1 uStack_71;
  undefined1 local_70;
  undefined1 local_6e;
  byte local_6c;
  undefined2 uStack_6a;
  char local_68;
  undefined1 uStack_67;
  undefined1 local_66;
  undefined1 local_64;
  char local_62;
  byte bStack_60;
  short local_5e;
  byte bStack_5c;
  undefined2 local_5a;
  char cStack_58;
  undefined1 uStack_57;
  undefined1 local_56;
  undefined1 local_54;
  byte local_52;
  undefined2 uStack_50;
  char local_4e;
  undefined1 uStack_4d;
  undefined1 local_4c;
  undefined1 local_4a;
  char local_48;
  byte bStack_46;
  short local_44;
  byte bStack_42;
  undefined2 local_40;
  char cStack_3e;
  undefined1 uStack_3d;
  undefined1 local_3c;
  undefined4 local_3a;
  undefined1 local_36;
  char local_34;
  short sStack_32;
  undefined2 local_30;
  char cStack_2e;
  undefined1 uStack_2d;
  undefined1 local_2c;
  undefined1 local_2a;
  byte local_28 [2];
  byte bStack_26;
  byte local_24;
  byte bStack_22;
  char local_20 [2];
  char cStack_1e;
  char cStack_1c;
  char local_1a;
  short sStack_18;
  short local_16;
  short sStack_14;
  short local_12;
  short sStack_10;
  short local_e;
  short sStack_c;
  short local_a;
  undefined2 uStack_8;
  undefined2 uStack_6;
  undefined4 uStack_4;
  
  uStack_8 = (undefined2)unaff_ESI;
  uStack_6 = (undefined2)((uint)unaff_ESI >> 0x10);
  uStack_4 = param_1;
  FUN_00407b9d((short *)local_20,param_2,(int)&sStack_10,local_28,&sStack_18,(short *)local_a0);
  *unaff_EBX = (byte)(local_3a >> 0x12) & 0xf | 0xd0;
  uVar2 = CONCAT11(local_3a._2_1_ << 6,local_36) & 0xffffff3f;
  unaff_EBX[1] = (byte)uVar2 | (byte)(uVar2 >> 8);
  unaff_EBX[2] = (byte)(sStack_32 >> 2) & 7 | local_34 << 3;
  unaff_EBX[3] = (byte)(CONCAT13(uStack_2d,CONCAT12(cStack_2e,local_30)) >> 0x12) & 3 |
                 ((byte)local_30 & 0xf) << 2 | (char)sStack_32 << 6;
  uVar2 = CONCAT11(cStack_2e << 6,local_2c) & 0xffffff07;
  uVar2 = CONCAT11((byte)(uVar2 >> 8) | (char)uVar2 << 3,local_2a) & 0xffffff07;
  unaff_EBX[4] = (byte)uVar2 | (byte)(uVar2 >> 8);
  unaff_EBX[5] = (byte)(sStack_10 >> 1) & 1 | local_20[0] * '\x02';
  unaff_EBX[6] = (byte)(sStack_18 >> 1) & 0x1f | (char)sStack_10 << 7 | (local_28[0] & 3) << 5;
  unaff_EBX[7] = ((byte)uStack_9e & 7) * '\x02' | (char)sStack_18 << 7 | (local_a0[0] & 7) << 4 |
                 (byte)(CONCAT13(uStack_9b,CONCAT12(local_9c,uStack_9e)) >> 0x12) & 1;
  uVar1 = CONCAT11(local_9a,local_9c << 6) & 0x7ff;
  uVar2 = CONCAT11((char)(uVar1 >> 8) << 3 | (byte)uVar1,local_98) & 0xffffff07;
  unaff_EBX[8] = (byte)uVar2 | (byte)(uVar2 >> 8);
  unaff_EBX[9] = (byte)(local_92 >> 1) & 3 | local_96 << 5 | (bStack_94 & 7) << 2;
  unaff_EBX[10] =
       (byte)(CONCAT13(uStack_8b,CONCAT12(cStack_8c,local_8e)) >> 0x12) & 1 |
       (char)local_92 << 7 | (bStack_90 & 7) << 4 | ((byte)local_8e & 7) * '\x02';
  uVar2 = CONCAT11(cStack_8c << 6,local_8a) & 0xffffff07;
  uVar2 = CONCAT11((byte)(uVar2 >> 8) | (char)uVar2 << 3,local_88) & 0xffffff07;
  unaff_EBX[0xb] = (byte)uVar2 | (byte)(uVar2 >> 8);
  unaff_EBX[0xc] = cStack_1e * '\x02' | (byte)(local_e >> 1) & 1;
  unaff_EBX[0xd] = (byte)(local_16 >> 1) & 0x1f | (char)local_e << 7 | (bStack_26 & 3) << 5;
  unaff_EBX[0xe] =
       (byte)(CONCAT13(uStack_81,CONCAT12(local_82,uStack_84)) >> 0x12) & 1 |
       ((byte)uStack_84 & 7) * '\x02' | (local_86 & 7) << 4 | (char)local_16 << 7;
  uVar2 = CONCAT11(local_82 << 6,local_80) & 0xffffff07;
  uVar2 = CONCAT11((byte)(uVar2 >> 8) | (char)uVar2 << 3,local_7e) & 0xffffff07;
  unaff_EBX[0xf] = (byte)uVar2 | (byte)(uVar2 >> 8);
  unaff_EBX[0x10] = (byte)(local_78 >> 1) & 3 | local_7c << 5 | (bStack_7a & 7) << 2;
  unaff_EBX[0x11] =
       (byte)(CONCAT13(uStack_71,CONCAT12(cStack_72,local_74)) >> 0x12) & 1 |
       (char)local_78 << 7 | (bStack_76 & 7) << 4 | ((byte)local_74 & 7) * '\x02';
  uVar2 = CONCAT11(cStack_72 << 6,local_70) & 0xffffff07;
  uVar2 = CONCAT11((byte)(uVar2 >> 8) | (char)uVar2 << 3,local_6e) & 0xffffff07;
  unaff_EBX[0x12] = (byte)uVar2 | (byte)(uVar2 >> 8);
  unaff_EBX[0x13] = (byte)(sStack_c >> 1) & 1 | cStack_1c * '\x02';
  unaff_EBX[0x14] = (byte)(sStack_14 >> 1) & 0x1f | (char)sStack_c << 7 | (local_24 & 3) << 5;
  unaff_EBX[0x15] =
       (byte)(CONCAT13(uStack_67,CONCAT12(local_68,uStack_6a)) >> 0x12) & 1 |
       (char)sStack_14 << 7 | (local_6c & 7) << 4 | ((byte)uStack_6a & 7) * '\x02';
  uVar2 = CONCAT11(local_68 << 6,local_66) & 0xffffff07;
  uVar1 = CONCAT11(local_64,(char)uVar2 << 3 | (byte)(uVar2 >> 8)) & 0x7ff;
  unaff_EBX[0x16] = (byte)uVar1 | (byte)(uVar1 >> 8);
  unaff_EBX[0x17] = (byte)(local_5e >> 1) & 3 | local_62 << 5 | (bStack_60 & 7) << 2;
  unaff_EBX[0x18] =
       (byte)(CONCAT13(uStack_57,CONCAT12(cStack_58,local_5a)) >> 0x12) & 1 |
       (char)local_5e << 7 | (bStack_5c & 7) << 4 | ((byte)local_5a & 7) * '\x02';
  uVar2 = CONCAT11(cStack_58 << 6,local_56) & 0xffffff07;
  uVar2 = CONCAT11((byte)(uVar2 >> 8) | (char)uVar2 << 3,local_54) & 0xffffff07;
  unaff_EBX[0x19] = (byte)uVar2 | (byte)(uVar2 >> 8);
  unaff_EBX[0x1a] = (byte)(local_a >> 1) & 1 | local_1a * '\x02';
  unaff_EBX[0x1b] = (byte)(local_12 >> 1) & 0x1f | (char)local_a << 7 | (bStack_22 & 3) << 5;
  unaff_EBX[0x1c] =
       (char)local_12 << 7 | (local_52 & 7) << 4 | ((byte)uStack_50 & 7) * '\x02' |
       (byte)(CONCAT13(uStack_4d,CONCAT12(local_4e,uStack_50)) >> 0x12) & 1;
  uVar2 = CONCAT11(local_4e << 6,local_4c) & 0xffffff07;
  uVar1 = CONCAT11(local_4a,(char)uVar2 << 3 | (byte)(uVar2 >> 8)) & 0x7ff;
  unaff_EBX[0x1d] = (byte)uVar1 | (byte)(uVar1 >> 8);
  unaff_EBX[0x1e] = (byte)(local_44 >> 1) & 3 | local_48 << 5 | (bStack_46 & 7) << 2;
  unaff_EBX[0x1f] =
       (byte)(CONCAT13(uStack_3d,CONCAT12(cStack_3e,local_40)) >> 0x12) & 1 |
       (char)local_44 << 7 | (bStack_42 & 7) << 4 | ((byte)local_40 & 7) * '\x02';
  uVar2 = CONCAT11(cStack_3e << 6,local_3c) & 0xffffff07;
  uVar2 = CONCAT11((byte)(uVar2 >> 8) | (char)uVar2 << 3,(undefined1)local_3a) & 0xffffff07;
  unaff_EBX[0x20] = (byte)uVar2 | (byte)(uVar2 >> 8);
  return;
}


