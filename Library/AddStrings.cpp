string addStrings(string num1, string num2) {
    int i = num1.length() - 1;
    int j = num2.length() - 1;
    int carry = 0;
    string ans = "";

    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry;
        if (i >= 0) {
            sum += num1[i] - '0';
            i--;
        }
        if (j >= 0) {
            sum += num2[j] - '0';
            j--;
        }
        ans = to_string(sum % 10) + ans;
        carry = sum / 10;
    }

    return ans;
}