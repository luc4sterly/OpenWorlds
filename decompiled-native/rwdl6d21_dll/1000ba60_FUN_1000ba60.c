// 1000ba60 FUN_1000ba60 [Global]
// program: RWDL6D21.DLL

int FUN_1000ba60(int param_1,int param_2,byte *param_3)

{
  return ((uint)param_3[2] * 2 -
         (int)(short)((ushort)(byte)(&DAT_1007c1d0)[*(byte *)((int)&DAT_1007bdb0 + param_2)] +
                     (ushort)(byte)(&DAT_1007c1d0)[*(byte *)((int)&DAT_1007bdb0 + param_1)])) *
         (int)(short)((ushort)(byte)(&DAT_1007c1d0)[*(byte *)((int)&DAT_1007bdb0 + param_1)] -
                     (ushort)(byte)(&DAT_1007c1d0)[*(byte *)((int)&DAT_1007bdb0 + param_2)]) +
         ((uint)param_3[1] * 2 -
         (int)(short)((ushort)(byte)(&DAT_1007c1d0)[*(byte *)((int)&DAT_1007bfc0 + param_2)] +
                     (ushort)(byte)(&DAT_1007c1d0)[*(byte *)((int)&DAT_1007bfc0 + param_1)])) *
         (int)(short)((ushort)(byte)(&DAT_1007c1d0)[*(byte *)((int)&DAT_1007bfc0 + param_1)] -
                     (ushort)(byte)(&DAT_1007c1d0)[*(byte *)((int)&DAT_1007bfc0 + param_2)]) +
         ((uint)*param_3 * 2 -
         (int)(short)((ushort)(byte)(&DAT_1007c1d0)[*(byte *)((int)&DAT_1007bec0 + param_2)] +
                     (ushort)(byte)(&DAT_1007c1d0)[*(byte *)((int)&DAT_1007bec0 + param_1)])) *
         (int)(short)((ushort)(byte)(&DAT_1007c1d0)[*(byte *)((int)&DAT_1007bec0 + param_1)] -
                     (ushort)(byte)(&DAT_1007c1d0)[*(byte *)((int)&DAT_1007bec0 + param_2)]);
}


