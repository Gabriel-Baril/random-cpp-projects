namespace hedron
{

	template<bool B> struct logic_not
	{
		static constexpr bool value = !B;
	};

	template<bool B> constexpr bool logic_not_v = logic_not<B>::value;

	template<bool B, bool... Bs>
	struct logic_nor
	{
		static constexpr bool value = !logic_or_v<B, Bs...>;
	};

	template<bool B, bool... Bs> constexpr bool logic_nor_v = logic_nor<B, Bs...>::value;

	template<bool B, bool... Bs>
	struct logic_nand
	{
		static constexpr bool value = !logic_and_v<B, Bs...>;
	};

	template<bool B, bool... Bs> constexpr bool logic_nand_v = logic_nand<B, Bs...>::value;

	template<bool B, bool... Bs>
	struct logic_xnor
	{
		static constexpr bool value = !logic_xor_v<B, Bs...>;
	};

	template<bool B, bool... Bs> constexpr bool logic_xnor_v = logic_xnor<B, Bs...>::value;

	template<bool B, bool... Bs>
	struct logic_and
	{
		static constexpr bool value = B && logic_and_v<Bs...>;
	};

	template<bool B>
	struct logic_and<B>
	{
		static constexpr bool value = B;
	};

	template<bool B, bool... Bs> constexpr bool logic_and_v = logic_and<B, Bs...>::value;

	template<bool B, bool... Bs>
	struct logic_or
	{
		static constexpr bool value = B || logic_or_v<Bs...>;
	};

	template<bool B>
	struct logic_or<B>
	{
		static constexpr bool value = B;
	};

	template<bool B, bool... Bs> constexpr bool logic_or_v = logic_or<B, Bs...>::value;

	template<bool B, bool... Bs>
	struct logic_xor
	{
		static constexpr bool value = B ^ logic_xor_v<Bs...>;
	};

	template<bool B>
	struct logic_xor<B>
	{
		static constexpr bool value = B;
	};

	template<bool B, bool... Bs> constexpr bool logic_xor_v = logic_xor<B, Bs...>::value;

}