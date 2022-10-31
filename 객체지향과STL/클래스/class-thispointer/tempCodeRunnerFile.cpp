struct Transaction {
    const int txId;
    const int fromId;
    const int toId;
    const int value;
    
    class Builder {
    private:
        int _fromId;
        int _toId;
        int _value;

    public:
        Transaction build() {
            int txId = _fromId ^ _toId ^ _value;
            return Transaction{txId, _fromId, _toId, _value};
        }
        
        Builder& setFromId(int fromId){
            _fromId = fromId;
            return *this;
        }

        Builder& setToId(int toId){
            _toId = toId;
            return *this;
        }

        Builder& setValue(int value){
            _value = value;
            return *this;
        }
    };
};

int main() {
    Transaction tx = Transaction::Builder()
    .setFromId(1234)
    .setToId(4321)
    .setValue(5678)
    .build();
}