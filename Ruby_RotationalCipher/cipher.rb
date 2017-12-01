class RotationalCipher
  def self.rotate(input, rotation)
    chars = input.chars.map do |i|
      if i =~ /[a-z]/
        ((i.ord + rotation - 'a'.ord) % 26 + 'a'.ord).chr
      elsif i =~ /[A-Z]/
        ((i.ord + rotation - 'A'.ord) % 26 + 'A'.ord).chr
      else
        i
      end
    end
    chars.join ''
  end
end
