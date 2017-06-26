-- SOURCE: http://rosettacode.org/wiki/Roman_numerals/Decode#Lua
-- SOURCE: http://rosettacode.org/wiki/Roman_numerals/Encode#Lua
-- Tested with the Busted framework for lua (luarocks install busted)

function ToNumeral( roman )
   local Num = { ["M"] = 1000, ["D"] = 500, ["C"] = 100, ["L"] = 50, ["X"] = 10, ["V"] = 5, ["I"] = 1 }
   local numeral = 0

   local i = 1
   local strlen = string.len(roman)
   while i < strlen do
       local z1, z2 = Num[ string.sub(roman,i,i) ], Num[ string.sub(roman,i+1,i+1) ]
       if z1 < z2 then
           numeral = numeral + ( z2 - z1 )
           i = i + 2
       else
           numeral = numeral + z1
           i = i + 1
       end
   end

   if i <= strlen then numeral = numeral + Num[ string.sub(roman,i,i) ] end

   return numeral
end


function FromNumeral( number )
  local romans = {
  {1000, "M"},
  {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
  {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"},
  {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"} }

  local roman = ""
  for _, v in ipairs(romans) do --note that this is -not- ipairs.
    value, letter = unpack(v)
    while number >= value do
      number = number - value
  	  roman = roman .. letter
    end
  end
  return roman
end
