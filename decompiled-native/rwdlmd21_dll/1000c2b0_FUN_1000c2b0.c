// 1000c2b0 FUN_1000c2b0 [Global]
// program: rwdlmd21.dll

int FUN_1000c2b0(int param_1,int param_2,byte *param_3)

{
  return ((uint)param_3[1] * 2 -
         (int)(short)((ushort)(byte)(&DAT_1008a210)[*(byte *)((int)&DAT_1008a000 + param_2)] +
                     (ushort)(byte)(&DAT_1008a210)[*(byte *)((int)&DAT_1008a000 + param_1)])) *
         (int)(short)((ushort)(byte)(&DAT_1008a210)[*(byte *)((int)&DAT_1008a000 + param_1)] -
                     (ushort)(byte)(&DAT_1008a210)[*(byte *)((int)&DAT_1008a000 + param_2)]) +
         ((uint)param_3[2] * 2 -
         (int)(short)((ushort)(byte)(&DAT_1008a210)[*(byte *)((int)&DAT_10089df0 + param_2)] +
                     (ushort)(byte)(&DAT_1008a210)[*(byte *)((int)&DAT_10089df0 + param_1)])) *
         (int)(short)((ushort)(byte)(&DAT_1008a210)[*(byte *)((int)&DAT_10089df0 + param_1)] -
                     (ushort)(byte)(&DAT_1008a210)[*(byte *)((int)&DAT_10089df0 + param_2)]) +
         ((uint)*param_3 * 2 -
         (int)(short)((ushort)(byte)(&DAT_1008a210)[*(byte *)((int)&DAT_10089f00 + param_2)] +
                     (ushort)(byte)(&DAT_1008a210)[*(byte *)((int)&DAT_10089f00 + param_1)])) *
         (int)(short)((ushort)(byte)(&DAT_1008a210)[*(byte *)((int)&DAT_10089f00 + param_1)] -
                     (ushort)(byte)(&DAT_1008a210)[*(byte *)((int)&DAT_10089f00 + param_2)]);
}


